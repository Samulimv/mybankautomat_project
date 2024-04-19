#include "mainwindow.h"
#include "pin.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    reader(new RFIDReader(this)),
    networkManager(new QNetworkAccessManager(this)),
    pinDialog(nullptr)
{
    ui->setupUi(this);


    connect(reader, &RFIDReader::newTagRead, this, &MainWindow::displayTagId);
    // connect(reader, &Rfidreader::errorOccured, statusLabel, &QLabel::setText);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleNetworkReply);

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

    //fetchPasswordFromServer(cleanedTagId);


    openPin();
}

void MainWindow::handlePinVerified(bool success)
{
    if (success)
    {
        // Logiikka, joka suoritetaan, jos PIN on oikein
        qDebug() << "PIN verification successful";
    } else {
        // Logiikka, jos PIN on väärä
        qDebug() << "PIN verification failed";
    }
}
void MainWindow::sendDataToServer(const QJsonObject &data)
{
    networkManager->post(request(), QJsonDocument(data).toJson());
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

void MainWindow::handleNetworkReply(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonObject obj = QJsonDocument::fromJson(response_data).object();
        QString password = obj["password"].toString();

        // Tarkistetaan, että saimme salasanan ennen PIN-dialogin avaamista.
        if (!password.isEmpty()) {
            // Avaa PIN-dialogi vain, jos salasana saadaan.
            openPin();
        } else {
            // Käsitellään tilannetta, jossa salasanaa ei saada.
            ui->statusLabel->setText("Tag recognized but no password provided.");
        }
    } else {
        qDebug() << "Verkkovirhe:" << reply->errorString();
        qDebug() << "Vastauksen statuskoodi:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "Vastauksen ruumis:" << reply->readAll();
        // Näytetään virhe käyttöliittymässä
        ui->statusLabel->setText("Network error: " + reply->errorString());
    }
    reply->deleteLater();
}
