#include "mainmenu.h"
#include "otto.h"
#include "ui_mainmenu.h"


mainmenu::mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
    on_stopmenu_clicked();

}

void mainmenu::on_tilinvalinta_clicked()
{
    //gredit tai debitin valinta
}


void mainmenu::on_tapahtumat_clicked()
{
    this->close();
    transactions *transactionsDialog = new transactions(this);
    transactionsDialog->exec();
}


void mainmenu::on_otto_clicked()
{
    this->close();
    otto *ottoDialog = new otto(this);
    ottoDialog->exec();
}


void mainmenu::on_saldo_clicked()
{

}


void mainmenu::on_stopmenu_clicked()
{
    close();
}

