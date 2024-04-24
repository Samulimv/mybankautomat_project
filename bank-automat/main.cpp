#include "mainwindow.h"
#include "transactions.h"
#include "pin.h"
#include "mainmenu.h"
#include <QApplication>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    transactions t;
    pin p;
    mainmenu m;

     t.show();
     w.show();
     m.show();

    return a.exec();
}
