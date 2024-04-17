#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





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
}

