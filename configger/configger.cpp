#include "configger.h"
#include "ui_configger.h"

Configger::Configger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Configger)
{
    ui->setupUi(this);

    QList<QString> configItems;
    QList<QString> configParams;

    // Create some data that is tabular in nature:
    configItems.append("Speed (m/sec)");
    configItems.append("Safety Range (cm)");
    configItems.append("Algorithm");
    configItems.append("X");
    configItems.append("Y");
    configItems.append("Z");
    configItems.append("S");
    configItems.append("T");
    configItems.append("U");

    configParams.append("0.7");
    configParams.append("60");
    configParams.append("TSP");
    configParams.append("N/A");
    configParams.append("N/A");
    configParams.append("N/A");
    configParams.append("N/A");
    configParams.append("N/A");
    configParams.append("N/A");


    // Create model:
    TConfigModel *ConfigModel = new class TConfigModel(this);

    // Populate model with data:
    ConfigModel->populateData(configItems, configParams);

    // Connect model to table view:
    ui->tableView->setModel(ConfigModel);

    // Make table header visible and display table:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    // Resize the column width automatically:
//    ui->tableView->resizeColumnsToContents();

    // Resize the column width manually:
    ui->tableView->setColumnWidth(0, 180);
    ui->tableView->setColumnWidth(1, 80);
}

Configger::~Configger()
{
    delete ui;
}

TConfigModel::TConfigModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TConfigModel::populateData(const QList<QString> &configItem, const QList<QString> &configParam)
{
    tm_config_item.clear();
    tm_config_item = configItem;

    tm_config_param.clear();
    tm_config_param = configParam;

    return;
}

int TConfigModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_config_item.length();
}

int TConfigModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TConfigModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    if (index.column() == 0) {
        return tm_config_item[index.row()];
    } else if (index.column() == 1) {
        return tm_config_param[index.row()];
    }

    return QVariant();
}

QVariant TConfigModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Item");
        } else if (section == 1) {
            return QString("Value");
        }
    }

    return QVariant();
}

Qt::ItemFlags TConfigModel::flags(const QModelIndex & index) const
{

}
