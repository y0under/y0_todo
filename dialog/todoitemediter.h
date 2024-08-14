#ifndef TODOITEMEDITER_H
#define TODOITEMEDITER_H

#include <QDialog>

namespace Ui {
class TodoItemEditer;
}

class TodoItemEditer : public QDialog
{
    Q_OBJECT

public:
    explicit TodoItemEditer(QWidget *parent = nullptr);
    ~TodoItemEditer();

private:
    Ui::TodoItemEditer *ui;

    void showCalendarDialog();
};

#endif // TODOITEMEDITER_H
