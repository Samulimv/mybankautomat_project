#include "transactions.h"
#include "ui_transactions.h"


transactions::transactions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transactions)
{
    ui->setupUi(this);
}

transactions::~transactions()
{
    delete ui;
}



void transactions::transactionsSlot(QNetworkReply *Treply)
{

    tapahtumat_Data=Treply->readAll();
    qDebug()<<"DATA : "+tapahtumat_Data;
    QJsonDocument json_doc = QJsonDocument::fromJson(tapahtumat_Data);
    QJsonArray json_array = json_doc.array();
    QString transact;
    transact="id_transaction | id_account | maara | tapahtuma | tilitapahtuman aika \r";

    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        transact+=QString::number(json_obj["id_transactions"].toInt())+"                            ";
        transact+=QString::number(json_obj["id_account"].toInt())+"                          ";
        transact+= json_obj["amount"].toString()+"             ";
        //transact+=QString::number(json_obj["amount"].toInt())+"      ";
        transact+=json_obj["transactionType"].toString()+"               ";
        transact+=json_obj["transactionDate"].toString()+"\r";


    }
    ui->textTransactions->setText(transact);

}

void transactions::on_btnTakaisin_clicked()
{

}

void transactions::setAccountId(const int &newAccountId)
{
    accountId = newAccountId;
}

void transactions::setWebToken(QByteArray &newWebToken)
{
    webToken= newWebToken;
}

void transactions::getTransactions()
{
    QString site_url="http://localhost:3000/transactions/"+accountId;
    QNetworkRequest request((site_url));
    qDebug()<<accountId;

    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    TManager = new QNetworkAccessManager(this);

    connect(TManager, SIGNAL(finished(QNetworkReply*)),this,
            SLOT(transactionsSlot(QNetworkReply*)));


    Treply = TManager->get(request);
}

