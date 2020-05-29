#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera/camera.h"
#include "motion/motion.h"
#include "logger/logger.h"
#include "configger/configger.h"
#include "status_monitor/status_monitor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Camera camera;
    camera.setParent(w.ui->groupBox_CameraView);
    camera.setGeometry(0, 0, 700, 500);
    camera.show();

    Motion motion;
    motion.setParent(w.ui->groupBox_MotionControl);
    motion.setGeometry(0, 30, 700, 300);
    motion.show();

    Logger logger;
    logger.setParent(w.ui->groupBox_LogWindow);
    logger.setGeometry(10, 20, 700, 460);
    logger.show();

    Configger configger;
    configger.setParent(w.ui->groupBox_Configuration);
    configger.setGeometry(10, 30, 300, 280);
    configger.show();

    StatusMonitor status_monitor;
    status_monitor.setParent(w.ui->groupBox_SystemStatus);
    status_monitor.setGeometry(10, 20, 300, 280);
    status_monitor.show();

    return a.exec();
}
