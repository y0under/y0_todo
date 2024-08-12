#include "mainwindow.h"
#include <QVBoxLayout>
#include <QStandardItem>
#include <QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), table_view(new QTableView(this)), model(new QStandardItemModel(this))
{
    // モデルの設定
    SetupModel();

    // QTableView の設定
    table_view->setModel(model);

    // QMainWindow のサイズ設定
    resize(800, 600); // 初期サイズの設定
    setMinimumSize(600, 400); // 最小サイズの設定
    setMaximumSize(1200, 800); // 最大サイズの設定

    // セントラルウィジェットを作成し、レイアウトを設定
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(table_view);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::SetupModel()
{
    // 日付と時刻のサンプルデータ
    QStringList date_headers;
    QStringList time_headers;

    // 日付の設定（例: 一週間分）
    QDate start_date = QDate::currentDate();
    for (int i = 0; i < 7; ++i) {
        date_headers << start_date.addDays(i).toString("yyyy-MM-dd");
    }

    // 時刻の設定（例: 一日の時間帯）
    QList<QTime> times = {QTime(9, 0), QTime(12, 0), QTime(15, 0), QTime(18, 0)};
    for (const QTime &time : times) {
        time_headers << time.toString("HH:mm");
    }

    // モデルのヘッダー設定
    model->setHorizontalHeaderLabels(date_headers);
    model->setVerticalHeaderLabels(time_headers);

    // TODOアイテムの設定
    for (int row = 0; row < time_headers.size(); ++row) {
        for (int col = 0; col < date_headers.size(); ++col) {
            QStandardItem *item = new QStandardItem();
            if (row % 2 == 0 && col % 2 == 0) {  // ダミーの条件
                item->setText("TODO Item (" + time_headers[row] + " on " + date_headers[col] + ")");
            }
            model->setItem(row, col, item);
        }
    }
}
