#include "otto.h"
#include "ui_otto.h"
#include "muusumma.h"
<<<<<<< HEAD

=======
>>>>>>> main
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

}


void otto::on_otto40_clicked()
{

}


void otto::on_otto60_clicked()
{

}


void otto::on_otto90_clicked()
{

}


void otto::on_otto140_clicked()
{

}


void otto::on_otto240_clicked()
{

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

