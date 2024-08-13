#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>

#include "widgets/infinitetablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTableView *table_view;
    // QStandardItemModel *model;
    widgets::InfiniteTableModel *model;
    QPushButton *add_btn;
    QPushButton *to_today_btn;

    void SetupModel();

    void onHorizontalScroll();
};
#endif // MAINWINDOW_H
