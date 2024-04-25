#include "otto.h"
#include "ui_otto.h"
#include "muusumma.h"
#include "environment.h"

otto::otto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::otto)
{
    ui->setupUi(this);
}

otto::~otto()
{
    delete ui;
}

void otto::on_otto20_clicked()
{
    maara=20;
    otto_clickHandler();
}


void otto::on_otto40_clicked()
{
    maara=40;
    otto_clickHandler();
}



void otto::on_otto60_clicked()
{
    maara=60;
    otto_clickHandler();
}




void otto::on_otto90_clicked()
{
    maara=90;
    otto_clickHandler();
}




void otto::on_otto140_clicked()
{
    maara=140;
    otto_clickHandler();
}



void otto::on_otto240_clicked()
{
    maara=240;
    otto_clickHandler();
}



void otto::on_muusumma_clicked()
{
    this->close();
    muusumma *muusummaDialog = new muusumma(this);
    muusummaDialog->exec();
}


void otto::on_alkuun_clicked()
{
    this->close();
    mainmenu *mainmenuDialog = new mainmenu(this);
    mainmenuDialog->exec();
}

void otto::ottoSlot(QNetworkReply *reply)
{
    reply->deleteLater();
    Manager->deleteLater();
}

void otto::setAccountIds(const QString &newAccountId,const QString &scndnewAccountId)
{
    accountId = newAccountId;
    scndAccountId = scndnewAccountId;
}

void otto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void otto::otto_clickHandler()
{
    QString accountId;
    int amount= maara;
    QString transType="nosto";

    QJsonObject jsonObj;
    jsonObj.insert("id_account", accountId);
    jsonObj.insert("amount ", amount);
    jsonObj.insert("TransactionType", transType);

    QString site_url=environment::getBaseUrl()+"/debit";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    Manager = new QNetworkAccessManager(this);
    connect(Manager, SIGNAL(finished (QNetworkReply*)), this, SLOT(ottoSlot(QNetworkReply*)));

    reply = Manager->post(request, QJsonDocument(jsonObj).toJson());



}

void otto::setCredOrDeb(const int &newCredOrDeb)
{
    credOrDeb=newCredOrDeb;

}

