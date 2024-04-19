#include "muusumma.h"
#include "ui_muusumma.h"

muusumma::muusumma(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::muusumma)
{
    ui->setupUi(this);


    connect(ui->muusumma1, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma2, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma3, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma4, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma5, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma6, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma7, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma8, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma9, &QPushButton::clicked, this, &muusumma::on_button_clicked);
    connect(ui->muusumma0, &QPushButton::clicked, this, &muusumma::on_button_clicked);
}

muusumma::~muusumma()
{
    delete ui;
    on_muusummaback_clicked();
}

void muusumma::on_muusummaback_clicked()
{
    this->close();
    otto *ottoDialog = new otto(this);
    ottoDialog->exec();
}


void muusumma::on_muusummaenter_clicked()
{

}

void muusumma::on_button_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

if (button) {
    QString buttonText = button->text();
    ui->lineEdit->setText(ui->lineEdit->text() + buttonText);
}}
