#ifndef CALENDARDIALOG_H
#define CALENDARDIALOG_H

#include <QDate>
#include <QDialog>

namespace Ui {
class CalendarDialog;
}

class CalendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarDialog(QWidget *parent = nullptr);
    ~CalendarDialog();

    QDate selectedDate() const;

private:
    Ui::CalendarDialog *ui;
    QDate date_;

    void onDateSelected();
};

#endif // CALENDARDIALOG_H
