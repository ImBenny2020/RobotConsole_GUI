#ifndef CONFIGGER_H
#define CONFIGGER_H

#include <QWidget>
#include <QAbstractTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Configger; }
QT_END_NAMESPACE

class TConfigModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TConfigModel(QObject *parent = 0);

    void populateData(const QList<QString> &configItem, const QList<QString> &configParam);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex & index) const Q_DECL_OVERRIDE;

private:
    QList<QString> tm_config_item;
    QList<QString> tm_config_param;

};

class Configger : public QWidget
{
    Q_OBJECT

public:
    Configger(QWidget *parent = nullptr);
    ~Configger();

private:
    Ui::Configger *ui;
};
#endif // CONFIGGER_H
