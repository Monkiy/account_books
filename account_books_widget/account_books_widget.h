#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_account_books_widget.h"

class account_books_widget : public QMainWindow
{
    Q_OBJECT

public:
    account_books_widget(QWidget *parent = Q_NULLPTR);

private:
    Ui::account_books_widgetClass ui;
};
