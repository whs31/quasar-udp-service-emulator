#ifndef ROOT_H
#define ROOT_H

#include <QMainWindow>
#include "src/saroutputconsoleemulator.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Root; }
QT_END_NAMESPACE

class Root : public QMainWindow
{
    Q_OBJECT

public:
    Root(QWidget *parent = nullptr);
    ~Root();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Root *ui;
    SAROutputConsoleEmulator* feedbackEmulator;
};
#endif // ROOT_H
