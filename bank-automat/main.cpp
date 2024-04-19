#include "mainwindow.h"
#include "transactions.h"
#include "pin.h"
#include <QApplication>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    transactions t;
    pin p;

    w.show();
    //t.show();
   // p.show();


    return a.exec();
}
