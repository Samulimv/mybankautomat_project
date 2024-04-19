#include "pin.h"
#include "ui_pin.h"
#include <QDebug>
#include <QLineEdit>
#include <QApplication>
#include <ostream>
#include <iostream>
#include "mainmenu.h"
pin::pin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pin)
{
    ui->setupUi(this);

    connect(ui->numero1, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero2, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero3, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero4, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero5, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero6, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero7, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero8, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero9, &QPushButton::clicked, this, &pin::on_button_clicked);
    connect(ui->numero0, &QPushButton::clicked, this, &pin::on_button_clicked);


    connect(ui->cancel, &QPushButton::clicked, this, &pin::on_cancel_clicked);

    connect(ui->clear, &QPushButton::clicked, this, &pin::on_clear_clicked);

    connect(ui->enter, &QPushButton::clicked, this, &pin::on_enter_clicked);

}

pin::~pin()
{
    delete ui;
    on_cancel_clicked();
}

void pin::on_button_clicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button) {
        QString buttonText = button->text();
        ui->lineEdit->setText(ui->lineEdit->text() + buttonText);
    }
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

void pin::on_cancel_clicked()
{
    // QApplication::quit(); // Sulkee kaikki sovellukset
    close(); //sulkee vain pin ikkunan
}

void pin::on_clear_clicked()
{
    ui->lineEdit->clear(); // Tyhjentää lineeditin
}

void pin::on_enter_clicked()
{
    QString pin = ui->lineEdit->text(); // Hae pin-koodi lineeditistä
    // Tässä voit toteuttaa tarvittavat toimenpiteet pin-koodin kanssa
    qDebug() << "Syötetty pin-koodi:" << pin;
    std::cout<<"pin oikein "<<std::endl;
    this->close(); //sulkee vain otto ikkunan, mainmenu jää taustalle
    mainmenu *mainmenuDialog = new mainmenu(this);
    mainmenuDialog->exec(); //sulkee ja avaa uuden menun
}
