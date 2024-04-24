#include "otto.h"
#include "ui_otto.h"
#include "muusumma.h"

otto::otto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::otto)
{
    ui->setupUi(this);
}

otto::~otto()
{
    delete ui;
}

void otto::on_otto20_clicked()
{
    maara=20;
    otto_clickHandler();
}


void otto::on_otto40_clicked()
{
    maara=40;
    otto_clickHandler();
}



void otto::on_otto60_clicked()
{
    maara=60;
    otto_clickHandler();
}




void otto::on_otto90_clicked()
{
    maara=90;
    otto_clickHandler();
}




void otto::on_otto140_clicked()
{
    maara=140;
    otto_clickHandler();
}



void otto::on_otto240_clicked()
{
    maara=240;
    otto_clickHandler();
}



void otto::on_muusumma_clicked()
{
    this->close();
    muusumma *muusummaDialog = new muusumma(this);
    muusummaDialog->exec();
}


void otto::on_alkuun_clicked()
{
    this->close();
    mainmenu *mainmenuDialog = new mainmenu(this);
    mainmenuDialog->exec();
}

void otto::setAccountId(const QString &newAccountId)
{
    accountId = newAccountId;
}

void otto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void otto::otto_clickHandler()
{


}

