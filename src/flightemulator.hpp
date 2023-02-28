#ifndef FLIGHTEMULATOR_H
#define FLIGHTEMULATOR_H

#include <QObject>
#include <QTimer>
#include <QGeoCoordinate>

#include "udpemulator.hpp"

class FlightEmulator : public QObject
{
    Q_OBJECT
public:
    explicit FlightEmulator(QObject *parent = nullptr);

    void startEmulator(void);
    void stopEmulator(void);

    void pitchChange(int value); //-1 to 1
    void rollChange(int value); //-1 to 1
    void yawChange(int Value); //-1 to 1
    void throttleChange(int Value); //-1 to 1

    struct Telemetry {
        double latitude = 0;
        double longitude = 0;
        float speed = 0;
        float elevation = 0;
        float direction = 0;
        short satellites = 5;
    }; Telemetry telemetry;

    struct Axes {
        float pitch = 0;
        float yaw = 0;
        float roll = 0;
        float throttle = 0;
    }; Axes axes;

protected:
    quint16 DEFAULT_UPDATE_PERIOD = 200; //ms
    QGeoCoordinate DEFAULT_COORDINATE = QGeoCoordinate(60.346, 30.78);
    float DEFAULT_SPEED = 50; //km-h
    float DEFAULT_ELEVATION = 100; //m

private:
    QTimer* yawTimer;
    QTimer* framerateTimer;

    float velocity_lat = 0;
    float velocity_lon = 0;

    void changeVelocity(void);
    void calculateVelocities(float azimuth, float velocity);
    void moveByVelocity(void);
    UDPEmulator* udpEmulator;

private slots:
//    void yawReset();

//    void Update(void);

};

#endif // FLIGHTEMULATOR_H
