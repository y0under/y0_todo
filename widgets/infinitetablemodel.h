#ifndef INFINITETABLEMODEL_H
#define INFINITETABLEMODEL_H

#include <QAbstractTableModel>
#include <QString>
#include <QDate>
#include <QTime>

namespace widgets {
class InfiniteTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    InfiniteTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setRowCount(int count);
    void setColumnCount(int count);
    void setTimeHeaders(const QStringList &headers);

private:
    int row_count_value = 1000; // 大きな行数
    int column_count_value = 1000; // 大きな列数
    QStringList time_headers;
};
}  // namespace widgets

#endif // INFINITETABLEMODEL_H
