#ifndef STATUSMONITOR_H
#define STATUSMONITOR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StatusMonitor; }
QT_END_NAMESPACE

class StatusMonitor : public QWidget
{
    Q_OBJECT

public:
    StatusMonitor(QWidget *parent = nullptr);
    ~StatusMonitor();

private:
    Ui::StatusMonitor *ui;
};
#endif // STATUSMONITOR_H
