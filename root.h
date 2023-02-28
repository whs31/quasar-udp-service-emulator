#ifndef ROOT_H
#define ROOT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Root; }
QT_END_NAMESPACE

class Root : public QMainWindow
{
    Q_OBJECT

public:
    Root(QWidget *parent = nullptr);
    ~Root();

private:
    Ui::Root *ui;
};
#endif // ROOT_H
