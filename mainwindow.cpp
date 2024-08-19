#include "mainwindow.h"
#include "dialog/todoitemediter.h"
#include "widgets/infinitetablemodel.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QScreen>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QScrollBar>

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
    // resize(800, 600); // 初期サイズの設定
        // スクリーンリストを取得
        QList<QScreen *> screens = QApplication::screens();
    if (!screens.isEmpty()) {
        // 最初のスクリーン（または適切なスクリーン）を選択
        QScreen *screen = screens.first();
        QRect screenGeometry = screen->availableGeometry();

        // macOSおよびiOSでのウィンドウサイズ設定
        this->setGeometry(screenGeometry);

        // ウィンドウを最大化する
        this->showMaximized();
    }

    // setMinimumSize(600, 400); // 最小サイズの設定
    // setMaximumSize(1200, 800); // 最大サイズの設定

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

    // buttun event
    connect(add_btn, &QPushButton::clicked, this, [this]() {
        TodoItemEditer edit_dialog(this);

        if (edit_dialog.exec() != QDialog::Accepted)
            return;

        // TODO: add data
    });

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

    // スクロールイベントの接続
    connect(table_view->horizontalScrollBar(), &QScrollBar::valueChanged, this, &MainWindow::onHorizontalScroll);
}

MainWindow::~MainWindow()
{
    delete table_view;
    delete model;
    delete add_btn;
    delete to_today_btn;
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
}

void MainWindow::onHorizontalScroll() {
    QScrollBar *scroll_bar = table_view->horizontalScrollBar();
    int scroll_bar_value = scroll_bar->value();
    int scroll_bar_max = scroll_bar->maximum();
    int scroll_bar_min = scroll_bar->minimum();
    int scroll_bar_page_step = scroll_bar->pageStep();

    // スクロールバーが右端に近づいたとき
    if (scroll_bar_value + scroll_bar_page_step >= scroll_bar_max) {
        model->expandToRight(10); // 右方向に10列追加
    }

    // スクロールバーが左端に近づいたとき
    if (scroll_bar_value <= scroll_bar_min) {
        // 左方向に10列追加
        model->expandToLeft(10);

        // 新しく追加された列数分だけスクロールバーの位置を調整
        int newScrollBarValue = scroll_bar_value + (10 * table_view->columnWidth(table_view->columnAt(0)));
        scroll_bar->setValue(newScrollBarValue);
    }
}
