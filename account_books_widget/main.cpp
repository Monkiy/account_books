#include "account_books_widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    account_books_widget w;
    w.show();
    return a.exec();
}
