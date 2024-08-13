#include "infinitetablemodel.h"

#include <QScrollBar>

namespace widgets {
InfiniteTableModel::InfiniteTableModel(QObject *parent)
    : QAbstractTableModel(parent),
      row_count_value(24),
      column_count_value(0),
      today_date(QDate::currentDate()) {}

int InfiniteTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return row_count_value; // 大きな行数を設定
}

int InfiniteTableModel::columnCount(const QModelIndex &parent ) const
{
    Q_UNUSED(parent);
    return column_count_value; // 大きな列数を設定
}

QVariant InfiniteTableModel::data(const QModelIndex &index, int role) const
{
    // TODO: set data
    return QVariant();

    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        // 行と列のインデックスに基づいてデータを生成
        return QString("TODO Item (%1, %2)").arg(index.row()).arg(index.column());
    }
    return QVariant();
}

QVariant InfiniteTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        // 列ヘッダー
        QDate date = today_date.addDays(section - today_column_index);
        return date.toString("yyyy-MM-dd");
    } else {
        // 行ヘッダー（時間）
        if (section >= 0 && section < time_headers.size()) {
            return time_headers.at(section);
        } else {
            return QVariant(); // 無効なインデックスには何も表示しない
        }
    }
}

void InfiniteTableModel::setRowCount(int count)
{
    row_count_value = count;
    emit layoutChanged();
}

void InfiniteTableModel::setColumnCount(int count)
{
    column_count_value = count;
    emit layoutChanged();
}

void InfiniteTableModel::setTimeHeaders(const QStringList &headers)
{
    time_headers = headers;
    emit layoutChanged();
}

void InfiniteTableModel::setDateHeaders(const QStringList &headers)
{
    date_headers = headers;
    emit headerDataChanged(Qt::Horizontal, 0, columnCount() - 1);
}

void InfiniteTableModel::setTodayColumnIndex(int index)
{
    today_column_index = index;
    emit layoutChanged();
}

int InfiniteTableModel::getTodayColumnIndex() const
{

    return today_column_index;
}

/**
 * @brief Handles left horizontal scroll events in the table view.
 * @param additional_columns : number of column for addition
 */
void InfiniteTableModel::expandToLeft(int additional_columns) {
    beginInsertColumns(QModelIndex(), 0, additional_columns - 1);

    // ヘッダーに追加するための基準を修正
    today_column_index += additional_columns;

    column_count_value += additional_columns;
    endInsertColumns();

    // ヘッダーの更新を通知
    emit headerDataChanged(Qt::Horizontal, 0, columnCount() - 1);
}

/**
 * @brief Handles right horizontal scroll events in the table view.
 * @param additional_columns : number of column for addition
 */
void InfiniteTableModel::expandToRight(int additional_columns) {
    beginInsertColumns(QModelIndex(), columnCount(), columnCount() + additional_columns - 1);

    // ヘッダーに追加するための基準を修正
    emit headerDataChanged(Qt::Horizontal, 0, columnCount() + additional_columns - 1);

    column_count_value += additional_columns;
    endInsertColumns();
}

}  // namespace widhets
