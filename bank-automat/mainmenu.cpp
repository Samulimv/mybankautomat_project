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
    QString site_url=environment::getBaseUrl()+"/card/getId"+cardNum;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    Manager = new QNetworkAccessManager(this);

    connect(Manager, SIGNAL(finished (QNetworkReply*)), this, SLOT(idAccountSlot(QNetworkReply*)));

    reply = Manager->get(request);

    otto *ottoObject =new otto(this);
    ottoObject->setWebToken(webToken);
    ottoObject->setAccountIds(accountId,scndAccountId);
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
    QString site_url=environment::getBaseUrl()+"/card/getId"+cardNum;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    Manager = new QNetworkAccessManager(this);

    connect(Manager, SIGNAL(finished (QNetworkReply*)), this, SLOT(idAccountSlot(QNetworkReply*)));

    reply = Manager->get(request);

}

void mainmenu::idAccountSlot(QNetworkReply *)
{
    response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    int credOrDeb=json_array.size();
    QString accountId=json_array[0].toString();
    QString scndAccountId=json_array[1].toString();
    qDebug()<<accountId;
    qDebug()<<credOrDeb;

    reply->deleteLater();
    Manager->deleteLater();




}

void mainmenu::setCardNum(const QString &newCardNum)
{
    cardNum= newCardNum;
}


void mainmenu::setWebToken(const QByteArray &newWebToken)
{
    webToken=newWebToken;
}


