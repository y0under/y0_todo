#include "todoitemediter.h"
#include "ui_todoitemediter.h"

TodoItemEditer::TodoItemEditer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TodoItemEditer)
{
    ui->setupUi(this);
}

TodoItemEditer::~TodoItemEditer()
{
    delete ui;
}
