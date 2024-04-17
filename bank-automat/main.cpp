#include "mainwindow.h"
#include "transactions.h"

#include <QApplication>
#include <QtSql>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    transactions t;
    w.show();
    t.show();


    return a.exec();
}
