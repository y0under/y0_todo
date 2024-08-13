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

    enum class Direction {
        Left = 0,
        Right,
        num_of_direction
    };

    InfiniteTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setRowCount(int count);
    void setColumnCount(int count);
    void setTimeHeaders(const QStringList &headers);

    void setDateHeaders(const QStringList &headers);

    void setTodayColumnIndex(int index);

    int getTodayColumnIndex() const;

    void expandToLeft(int additional_columns);
    void expandToRight(int additional_columns);

private:
    int row_count_value = 1000; // 大きな行数
    int column_count_value = 1000; // 大きな列数
    int today_column_index;
    QStringList time_headers;
    QStringList date_headers;
    QDate today_date;    

};
}  // namespace widgets

#endif // INFINITETABLEMODEL_H
