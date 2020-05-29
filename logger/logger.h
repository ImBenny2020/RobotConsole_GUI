#ifndef LOGGER_H
#define LOGGER_H

#include <QWidget>
#include <QAbstractTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Logger; }
QT_END_NAMESPACE

class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TestModel(QObject *parent = 0);

    void populateData(const QList<QString> &recordId, const QList<QString> &recordDate, const QList<QString> &recordTime,
                      const QList<QString> &recordGroup, const QList<QString> &recordMessage, const QList<QString> &recordLevel);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_record_id;
    QList<QString> tm_record_date;
    QList<QString> tm_record_time;
    QList<QString> tm_record_group;
    QList<QString> tm_record_message;
    QList<QString> tm_record_level;

};

class Logger : public QWidget
{
    Q_OBJECT

public:
    Logger(QWidget *parent = nullptr);
    ~Logger();

private:
    Ui::Logger *ui;
};
#endif // LOGGER_H
