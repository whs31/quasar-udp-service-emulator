#ifndef ROOT_H
#define ROOT_H

#include <QMainWindow>
#include <QSet>
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
    bool eventFilter(QObject* obj, QEvent* event);

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Root *ui;
    QSet<int> pressedKeys;
    SAROutputConsoleEmulator* feedbackEmulator;
};
#endif // ROOT_H
