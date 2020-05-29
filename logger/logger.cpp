#include "logger.h"
#include "ui_logger.h"

Logger::Logger(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Logger)
{
    ui->setupUi(this);

    QList<QString> recordIds;
    QList<QString> recordDates;
    QList<QString> recordTimes;
    QList<QString> recordGroups;
    QList<QString> recordMessages;
    QList<QString> recordLevels;


    // Create some data that is tabular in nature:
    recordIds.append("1");
    recordIds.append("2");
    recordIds.append("3");
    recordDates.append("2020-05-27");
    recordDates.append("2020-05-27");
    recordDates.append("2020-05-28");
    recordTimes.append("11:11:11");
    recordTimes.append("12:12:12");
    recordTimes.append("13:13:13");
    recordGroups.append("Motion");
    recordGroups.append("Camera");
    recordGroups.append("System");
    recordMessages.append("Initialization OK.");
    recordMessages.append("Connection Fail.");
    recordMessages.append("Network Unstable.");
    recordLevels.append("Nofity");
    recordLevels.append("Alarm");
    recordLevels.append("Warn");

    // Create model:
    TestModel *LogModel = new TestModel(this);

    // Populate model with data:
    LogModel->populateData(recordIds, recordDates, recordTimes, recordGroups, recordMessages, recordLevels);

    // Connect model to table view:
    ui->tableView->setModel(LogModel);

    // Make table header visible and display table:
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    // Resize the column width automatically:
    ui->tableView->resizeColumnsToContents();

    // Specify some column widths:
    ui->tableView->setColumnWidth(4, 280);
    ui->tableView->setColumnWidth(5, 100);
}

Logger::~Logger()
{
    delete ui;
}

TestModel::TestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
void TestModel::populateData(const QList<QString> &recordId, const QList<QString> &recordDate, const QList<QString> &recordTime,
                             const QList<QString> &recordGroup, const QList<QString> &recordMessage, const QList<QString> &recordLevel)
{
    tm_record_id.clear();
    tm_record_id = recordId;

    tm_record_date.clear();
    tm_record_date = recordDate;

    tm_record_time.clear();
    tm_record_time = recordTime;

    tm_record_group.clear();
    tm_record_group = recordGroup;

    tm_record_message.clear();
    tm_record_message = recordMessage;

    tm_record_level.clear();
    tm_record_level = recordLevel;

    return;
}

int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_record_id.length();
}

int TestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    if (index.column() == 0) {
        return tm_record_id[index.row()];
    } else if (index.column() == 1) {
        return tm_record_date[index.row()];
    } else if (index.column() == 2) {
        return tm_record_time[index.row()];
    } else if (index.column() == 3) {
        return tm_record_group[index.row()];
    } else if (index.column() == 4) {
        return tm_record_message[index.row()];
    } else if (index.column() == 5) {
        return tm_record_level[index.row()];
    }

    return QVariant();
}

QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("ID");
        } else if (section == 1) {
            return QString("Date");
        } else if (section == 2) {
            return QString("Time");
        } else if (section == 3) {
            return QString("Group");
        } else if (section == 4) {
            return QString("Message");
        } else if (section == 5) {
            return QString("Level");
        }
    }

    return QVariant();
}
