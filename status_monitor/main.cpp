#include "status_monitor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StatusMonitor w;
    w.show();
    return a.exec();
}
