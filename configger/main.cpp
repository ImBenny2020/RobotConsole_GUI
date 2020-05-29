#include "configger.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Configger w;
    w.show();
    return a.exec();
}
