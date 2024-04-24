#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    reader(new RFIDReader(this)),
  //  networkManager(new QNetworkAccessManager(this)),
    pinDialog(nullptr)
{
    ui->setupUi(this);
    connect(reader, &RFIDReader::newTagRead, this, &MainWindow::displayTagId);

    if(!reader->connectToReader("COM3"))
    {

    }


}

MainWindow::~MainWindow()
{
    delete ui;
    delete reader;
   // delete networkManager;
    delete pinDialog;
}


void MainWindow::displayTagId(const QString &tagId)
{
    QString cleanedTagId = tagId;
    cleanedTagId.remove('-');
    cleanedTagId.remove("\\s");
    cleanedTagId.remove('>');
    card=cleanedTagId;
    openPin();
}

QString MainWindow::returnCardNumber()const
{

    return card;
}


void MainWindow::openPin()
{
    if (!pinDialog)
    {
        pinDialog = new pin(this);
        pinDialog->setModal(true);
    }
    if (!pinDialog->isVisible())
    {
        pinDialog->exec();
    }
}













