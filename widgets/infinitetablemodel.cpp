#include "infinitetablemodel.h"

namespace widgets {
InfiniteTableModel::InfiniteTableModel(QObject *parent)
    : QAbstractTableModel(parent),
      row_count_value(24),
      column_count_value(0) {}

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
        // 横のヘッダー（例: 日付）
        return QString("Date %1").arg(section);
    } else {
        // 縦のヘッダー（例: 時刻）
        return time_headers.at(section);
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
}  // namespace widhets
