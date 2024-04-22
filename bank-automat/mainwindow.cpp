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
     cleanedTagId.remove(("\\s"));
     cleanedTagId.remove('>');
     cleanedTagId = cleanedTagId.trimmed();
     pin * objectPin = new pin(this);
     objectPin -> returnCardNumber(cleanedTagId);
     qDebug() << "cleaned" << cleanedTagId;
     openPin();

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













