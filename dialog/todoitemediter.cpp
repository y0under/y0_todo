#include "todoitemediter.h"
#include "ui_todoitemediter.h"
#include "calendardialog.h"

#include <QCalendarWidget>

TodoItemEditer::TodoItemEditer(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::TodoItemEditer)
{
    ui->setupUi(this);

    ui->task_date->setDate(QDate::currentDate());

    connect(ui->select_date_button, &QPushButton::clicked, this, &TodoItemEditer::showCalendarDialog);
}

TodoItemEditer::~TodoItemEditer()
{
    delete ui;
}

void TodoItemEditer::showCalendarDialog()
{
    CalendarDialog calendar_dialog(this);
    if (calendar_dialog.exec() != QDialog::Accepted)
        return;

    QDate selected_date = calendar_dialog.selectedDate();
    ui->task_date->setDate(selected_date);
}
