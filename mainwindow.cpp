#include "mainwindow.h"
#include "widgets/infinitetablemodel.h"
#include <QVBoxLayout>
#include <QStandardItem>
#include <QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), table_view(new QTableView(this)), model(new widgets::InfiniteTableModel(this)),
      add_btn(new QPushButton("追加", this)), to_today_btn(new QPushButton("今日", this))
{
    // モデルの設定
    SetupModel();

    // add_btn->setGeometry(50, this->y() + this->height() + 5, add_btn->width(), add_btn->height());

    // QTableView の設定
    table_view->setModel(model);
    table_view->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    table_view->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    // table_view->setFixedHeight(500);

    // QMainWindow のサイズ設定
    resize(800, 600); // 初期サイズの設定
    setMinimumSize(600, 400); // 最小サイズの設定
    setMaximumSize(1200, 800); // 最大サイズの設定

    // セントラルウィジェットを作成し、レイアウトを設定
    QWidget *central_widget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(central_widget);
    layout->addWidget(table_view, 0, 0, 1, 2);

    // ボタンのサイズを設定
    add_btn->setFixedWidth(100); // 固定幅設定
    to_today_btn->setFixedWidth(100); // 固定幅設定

    // ボタンのレイアウト設定
    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(add_btn);
    button_layout->addWidget(to_today_btn);
    // button_layout->setAlignment(Qt::AlignLeft);

    // 左側のスペースを追加
    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    button_layout->addSpacerItem(spacer);

    // ボタンのレイアウトを追加
    layout->addLayout(button_layout, 1, 0, 1, 2);

    central_widget->setLayout(layout);
    setCentralWidget(central_widget);

    // 初期スクロール位置を設定
    QModelIndex today_index = model->index(0, model->getTodayColumnIndex());
    table_view->scrollTo(today_index, QAbstractItemView::PositionAtCenter);
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
    QDate startDate = QDate::currentDate();
    for (int i = -7; i < 7; ++i) {
        date_headers << startDate.addDays(i).toString("yyyy-MM-dd");
    }

    // 時刻の設定（例: 一日の時間帯）
    for (int hour = 0; hour < 24; ++hour) {
        time_headers << QString::asprintf("%02d:00", hour);
    }

    // モデルのヘッダー設定
    model->setColumnCount(date_headers.size());
    model->setTimeHeaders(time_headers);
    // model->setRowCount(timeHeaders.size());

    model->setRowCount(time_headers.size());
    model->setColumnCount(date_headers.size());
    model->setTimeHeaders(time_headers);
    model->setTodayColumnIndex(date_headers.indexOf(QDate::currentDate().toString("yyyy-MM-dd")));


    // ヘッダーのラベル設定（必要な場合はInfiniteTableModel内で設定されます）
}
