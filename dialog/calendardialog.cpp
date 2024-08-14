#include "calendardialog.h"
#include "ui_calendardialog.h"

#include <QPushButton>

CalendarDialog::CalendarDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalendarDialog)
{
    ui->setupUi(this);

    connect(ui->calendar_widget, &QCalendarWidget::clicked, this, &CalendarDialog::onDateSelected);
    connect(ui->ok_cancel_buttonBox->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &CalendarDialog::accept);
}

CalendarDialog::~CalendarDialog()
{
    delete ui;
}

QDate CalendarDialog::selectedDate() const
{
    return date_;
}

void CalendarDialog::onDateSelected()
{
    date_ = ui->calendar_widget->selectedDate();
}
