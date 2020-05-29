#ifndef MOTION_H
#define MOTION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Motion; }
QT_END_NAMESPACE

class Motion : public QMainWindow
{
    Q_OBJECT

public:
    Motion(QWidget *parent = nullptr);
    ~Motion();

private:
    Ui::Motion *ui;
};
#endif // MOTION_H
