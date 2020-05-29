#include "status_monitor.h"
#include "ui_status_monitor.h"

StatusMonitor::StatusMonitor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatusMonitor)
{
    ui->setupUi(this);
}

StatusMonitor::~StatusMonitor()
{
    delete ui;
}

