#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "mainwindow.h"
#include "transactions.h"

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_tilinvalinta_clicked();
    void on_tapahtumat_clicked();
    void on_otto_clicked();
    void on_saldo_clicked();
    void on_stopmenu_clicked();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
