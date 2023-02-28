#include "udpemulator.hpp"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostAddress>

UDPEmulator::UDPEmulator(QObject *parent)
    : QObject{parent}
{
    m_socket = new QUdpSocket(this);
    if (!m_socket->bind(QHostAddress("127.0.0.1"), telemetryPort.toUInt())) {
        qCritical() << "[EMULATOR] Failed to bind the UDP telemetry socket emulator to the address and port.";
    } else {
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(readSlot()));
    }
}

QByteArray UDPEmulator::jsonEncode(float latitude, float longitude, float speed, float elevation, int satellites, float pitch, float roll) {
    QJsonObject jsonData;
    jsonData["Latitude"] = latitude;
    jsonData["Longitude"] = longitude;
    jsonData["Speed"] = speed;
    jsonData["Elevation"] = elevation;
    jsonData["Sats"] = satellites;
    jsonData["Pitch"] = pitch;
    jsonData["Roll"] = roll;

    QJsonDocument jsonDoc(jsonData);
    return "$JSON" + jsonDoc.toJson();
}

void UDPEmulator::readSlot()
{
    while (m_socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_socket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        m_socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        if (datagram == "$JSON") {
            m_socket->writeDatagram(jsonEncode(emulatorTelemetry.latitude, emulatorTelemetry.longitude,
                                               emulatorTelemetry.speed, emulatorTelemetry.elevation,
                                               emulatorTelemetry.sats, emulatorTelemetry.pitch, emulatorTelemetry.roll), sender, senderPort);
        }
    }
}

UDPEmulator::~UDPEmulator()
{
    m_socket->disconnect();
}
