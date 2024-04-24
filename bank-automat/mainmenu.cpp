#include "ui_mainmenu.h"
#include "mainmenu.h"
#include "transactions.h"
#include "ui_transactions.h"



mainmenu::mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;


}

void mainmenu::on_tilinvalinta_clicked()
{
    //gredit tai debitin valinta
}


void mainmenu::on_tapahtumat_clicked()
{
    transactions *objectTransactions= new transactions(this);
    objectTransactions->setWebToken(webToken);
    objectTransactions->getTransactions();
    objectTransactions->show();


}


void mainmenu::on_otto_clicked()
{

}


void mainmenu::on_saldo_clicked()
{

}


void mainmenu::on_stopmenu_clicked()
{
    close();
}
void mainmenu::setWebToken(const QByteArray &newWebToken)
{
    webToken=newWebToken;
}

