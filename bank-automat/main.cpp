#include "mainwindow.h"
#include "transactions.h"
#include "pin.h"
#include "mainmenu.h"

#include <QApplication>
#include <QtSql>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    transactions t;
    pin p;
    mainmenu m;

     w.show();
     //t.show();
     //p.show();
    //m.show();

    return a.exec();
}
