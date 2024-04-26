#include "tilinvalinta.h"
#include "ui_tilinvalinta.h"

tilinvalinta::tilinvalinta(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tilinvalinta)
{
    ui->setupUi(this);
}

tilinvalinta::~tilinvalinta()
{
    delete ui;
}

void tilinvalinta::on_takaisin_clicked()
{
    this->close();
}


void tilinvalinta::on_debit_clicked()
{

}


void tilinvalinta::on_credit_clicked()
{

}

