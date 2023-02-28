#include "root.hpp"
#include "./ui_root.h"
#include <QKeyEvent>

Root::Root(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Root)
{
    ui->setupUi(this);
    feedbackEmulator = new SAROutputConsoleEmulator(this);
}

Root::~Root()
{
    delete ui;
}

bool Root::eventFilter(QObject * obj, QEvent * event)
{
    if ( event->type() == QEvent::KeyPress ) {
        pressedKeys += (static_cast<QKeyEvent*>(event))->key();
//            if ( pressedKeys.contains(Qt::Key_W) || pressedKeys.contains(1062) ) { flightEmulator->pitchChange(-1); }
//            if ( pressedKeys.contains(Qt::Key_S) || pressedKeys.contains(1067)) { flightEmulator->pitchChange(1); }
//            if ( pressedKeys.contains(Qt::Key_A) || pressedKeys.contains(1060)) { flightEmulator->yawChange(-1); }
//            if ( pressedKeys.contains(Qt::Key_D) || pressedKeys.contains(1042)) { flightEmulator->yawChange(1); }
//            if ( pressedKeys.contains(Qt::Key_Q) || pressedKeys.contains(1049)) { flightEmulator->rollChange(-1); }
//            if ( pressedKeys.contains(Qt::Key_E) || pressedKeys.contains(1059)) { flightEmulator->rollChange(1); }
//            if ( pressedKeys.contains(Qt::Key_Z) || pressedKeys.contains(1071)) { flightEmulator->throttleChange(1); }
//            if ( pressedKeys.contains(Qt::Key_X) || pressedKeys.contains(1063)) { flightEmulator->throttleChange(-1); }
        return 1;
    }
    else if ( event->type() == QEvent::KeyRelease ) { pressedKeys -= (static_cast<QKeyEvent*>(event))->key(); return 1; }
    else
        return QObject::eventFilter(obj, event);
    return false;
}


void Root::on_lineEdit_textChanged(const QString &arg1)
{

}


void Root::on_lineEdit_4_textChanged(const QString &arg1)
{
    feedbackEmulator->terminalPort = arg1;
}


void Root::on_pushButton_clicked()
{
    feedbackEmulator->sampleTest();
}

