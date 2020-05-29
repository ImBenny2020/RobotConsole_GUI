#include "motion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Motion motion;
    motion.show();
    return a.exec();
}
