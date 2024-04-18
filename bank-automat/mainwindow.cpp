#include "mainwindow.h"
#include "pin.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "rfidreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    reader(new Rfidreader(this)),
    //statusLabel(new QLabel(this)),
    networkManager(new QNetworkAccessManager(this)),
    pinDialog(nullptr) // Alustetaan pinDialog osoittamaan nullptr:ia
{
    ui->setupUi(this);
    // ui->statusLabel->setText("SYÖTÄ KORTTI");

    connect(reader, &Rfidreader::newTagRead, this, &MainWindow::displayTagId);
    // connect(reader, &Rfidreader::errorOccured, statusLabel, &QLabel::setText);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::handleNetworkReply);

    if (!reader->connectToReader("COM3"))
    {
        //statusLabel->setText("could not connect to RFID reader");
        QMessageBox::warning(this, "Connection Error", "Could not connect to RFID reader");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete reader;
    delete networkManager;
    // Varmista, että pinDialog vapautetaan muistista
    delete pinDialog;
}

void MainWindow::displayTagId(const QString &tagId)
{
    QString cleanedTagId = tagId;
    cleanedTagId.remove('-'); // Poistetaan viiva

    // statusLabel->setText("Tag read: " + cleanedTagId); // Käytetään puhdistettua tagin ID:tä
    fetchPasswordFromServer(cleanedTagId); // Käytetään puhdistettua tagin ID:tä

    // Kutsu openPin() -funktiota vasta kun kortti on luettu
    openPin();
}



void MainWindow::fetchPasswordFromServer(const QString &tagId)
{
    QUrl url("http://localhost:3000/card");
    QNetworkRequest request(url);

    // Lisätään Content-Type otsikko
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Oletetaan, että käyttäjätunnus on 'user' ja salasana on 'password'
    QString credentials = "user:password";
    QByteArray basicAuth = "Basic " + credentials.toLocal8Bit().toBase64();
    request.setRawHeader("Authorization", basicAuth);

    QJsonObject json;
    json["cardNumber"] = tagId;

    networkManager->post(request, QJsonDocument(json).toJson());
}


void MainWindow::handlePinVerified(bool success)
{
    if (success) {
        // Logiikka, joka suoritetaan, jos PIN on oikein
        qDebug() << "PIN verification successful";
    } else {
        // Logiikka, jos PIN on väärä
        qDebug() << "PIN verification failed";
    }
}
void MainWindow::sendDataToServer(const QJsonObject &data)
{
    QUrl url("http://your-backend-url.com/api/data");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    networkManager->post(request, QJsonDocument(data).toJson());
}

void MainWindow::openPin() {
    if (!pinDialog) { // Luo pinDialog vain, jos sitä ei ole vielä luotu
        pinDialog = new pin(this);
        pinDialog->setModal(true); // Aseta dialogi modaaliksi
    }
    if (!pinDialog->isVisible()) {
        pinDialog->exec(); // Näytä PIN-ikkuna vain, jos se ei ole jo näkyvissä
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
