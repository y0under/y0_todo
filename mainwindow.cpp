#include "mainwindow.h"
#include "widgets/infinitetablemodel.h"
#include <QVBoxLayout>
#include <QStandardItem>
#include <QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), table_view(new QTableView(this)), model(new widgets::InfiniteTableModel(this))
{
    // モデルの設定
    SetupModel();

    // QTableView の設定
    table_view->setModel(model);
    table_view->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    table_view->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

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
    QStringList dateHeaders;
    QStringList timeHeaders;

    // 日付の設定（例: 一週間分）
    QDate startDate = QDate::currentDate();
    for (int i = 0; i < 7; ++i) {
        dateHeaders << startDate.addDays(i).toString("yyyy-MM-dd");
    }

    // 時刻の設定（例: 一日の時間帯）
    for (int hour = 0; hour < 24; ++hour) {
        timeHeaders << QString::asprintf("%02d:00", hour);
    }

    // モデルのヘッダー設定
    model->setColumnCount(dateHeaders.size());
    model->setTimeHeaders(timeHeaders);
    // model->setRowCount(timeHeaders.size());

    // ヘッダーのラベル設定（必要な場合はInfiniteTableModel内で設定されます）
}
