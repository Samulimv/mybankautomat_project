#include "mainwindow.h"
#include "pin.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD
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
=======
#include "environment.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

>>>>>>> 260d6aef8108fd1cc5db7e0573321cb19adbff30
}

MainWindow::~MainWindow()
{
    delete ui;
    delete reader;
    delete networkManager;
    // Varmista, että pinDialog vapautetaan muistista
    delete pinDialog;
}

<<<<<<< HEAD
void MainWindow::displayTagId(const QString &tagId)
{
    QString cleanedTagId = tagId;
    cleanedTagId.remove('-'); // Poistetaan viiva



    // Kutsu openPin() -funktiota vasta kun kortti on luettu
    openPin();
}

QString MainWindow::returnCardNumber()
{
    return cleanedTagId;
}

void MainWindow::openPin() {
    if (!pinDialog) { // Luo pinDialog vain, jos sitä ei ole vielä luotu
        pinDialog = new pin(this);
        pinDialog->setModal(true); // Aseta dialogi modaaliksi
    }
    if (!pinDialog->isVisible()) {
        pinDialog->exec(); // Näytä PIN-ikkuna vain, jos se ei ole jo näkyvissä
    }
=======




void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QMessageBox msgBox;
    //qDebug()<<response_data;
    if(response_data=="-4078" || response_data.length()==0){

        msgBox.setText("Virhe tietoyhteydessä");
        msgBox.exec();
    }
    else{
        if(response_data!="false"){
            //kirjautuminen onnistui

            msgBox.setText("success");
            msgBox.exec();
        }
        else{
            msgBox.setText("Tunnus/salasana ei täsmää");
            msgBox.exec();
            //ui->textUsername->clear();
            ui->textPin->clear();
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}







void MainWindow::on_btnLogin_clicked()
{
    QString cardNum=ui->textCardNumber->text();
    QString pin=ui->textPin->text();
    QJsonObject jsonObj;
    jsonObj.insert("cardNumber",cardNum);
    jsonObj.insert("pin",pin);

    QString site_url=Environment::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
>>>>>>> 260d6aef8108fd1cc5db7e0573321cb19adbff30
}

