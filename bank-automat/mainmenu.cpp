#include "ui_mainmenu.h"
#include "mainmenu.h"
#include "transactions.h"
#include "ui_transactions.h"
#include "otto.h"
#include "saldo.h"
#include "environment.h"
#include "QDebug"


mainmenu::mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;


}

void mainmenu::on_tilinvalinta_clicked()
{
    //gredit tai debitin valinta
}



void mainmenu::on_tapahtumat_clicked()
{
    transactions *objectTransactions= new transactions(this);
    objectTransactions->setAccountId(accountId);
    objectTransactions->setWebToken(webToken);
    objectTransactions->getTransactions();
    objectTransactions->show();


}


void mainmenu::on_otto_clicked()
{


    otto *ottoObject =new otto(this);
    ottoObject->setWebToken(webToken);
    ottoObject->setAccountIds(accountId);
    ottoObject->setCredOrDeb(credOrDeb);
    ottoObject->show();

}


void mainmenu::on_saldo_clicked()
{
    this->close();
    saldo *saldoDialog = new saldo(this);
    saldoDialog->exec();

}


void mainmenu::on_stopmenu_clicked()
{
    close();
}
void mainmenu:: idAccount()
{
    QString site_url="http://localhost:3000/card/getId/"+cardNum;
    QNetworkRequest request((site_url));
    qDebug()<<cardNum;
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    mainManager = new QNetworkAccessManager(this);

    connect(mainManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(idAccountSlot(QNetworkReply*)));

    mainReply = mainManager->get(request);

}

void mainmenu::idAccountSlot(QNetworkReply *mainReply)
{
    main_data=mainReply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(main_data);
    QJsonArray json_array = json_doc.array();
    qDebug()<<json_array;
     credOrDeb=json_array.size();
     accountId=json_array.at(0)["id_account"].toInt();
     scndAccountId=json_array.at(1)["id_account"].toInt();
    qDebug()<<accountId;
    qDebug()<<credOrDeb;
    qDebug()<<scndAccountId;

    mainReply->deleteLater();
    mainManager->deleteLater();




}

void mainmenu::setCardNum(const QString &newCardNum)
{
    cardNum= newCardNum;
}


void mainmenu::setWebToken(const QByteArray &newWebToken)
{
    webToken=newWebToken;
}


