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
}

