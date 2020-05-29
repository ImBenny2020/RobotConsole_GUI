#include "motion.h"
#include "ui_motion.h"

Motion::Motion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Motion)
{
    ui->setupUi(this);
}

Motion::~Motion()
{
    delete ui;
}

