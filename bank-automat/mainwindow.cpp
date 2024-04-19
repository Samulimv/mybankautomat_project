#include "mainwindow.h"
#include "pin.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,reader(new RFIDReader(this))
    ,networkManager(new QNetworkAccessManager(this))
    ,pinDialog(nullptr)
{
    ui->setupUi(this);


    connect(reader, &RFIDReader::newTagRead, this, &MainWindow::displayTagId);
    // connect(reader, &Rfidreader::errorOccured, statusLabel, &QLabel::setText);


    if (!reader->connectToReader("COM3"))
    {

        QMessageBox::warning(this, "Connection Error", "Could not connect to RFID reader");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
    delete reader;
    delete networkManager;
    delete pinDialog;
}


void MainWindow::displayTagId(const QString &tagId)
{
    QString cleanedTagId = tagId;
    cleanedTagId.remove('-');

    



    openPin();
}

QString MainWindow::returnCardNumber()
{
    return cleanedTagId;
}

void MainWindow::openPin() {
    if (!pinDialog) {
        pinDialog = new pin(this);
        pinDialog->setModal(true);
    }
    if (!pinDialog->isVisible()) {
        pinDialog->exec();
    }
}













