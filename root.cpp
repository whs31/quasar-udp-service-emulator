#include "root.hpp"
#include "./ui_root.h"

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

