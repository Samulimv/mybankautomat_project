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


void transactions::on_btnShowTrans_clicked()
{
    QString site_url="http://localhost:3000/transactions";
    QNetworkRequest request((site_url));
    /*/WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    WEBTOKEN LOPPU */
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)),this,
            SLOT(transactionsSlot(QNetworkReply*)));


    reply = getManager->get(request);
}

void transactions::transactionsSlot(QNetworkReply *reply)
{

    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transact;
      transact="id_transaction | id_account | maara | tapahtuma | tilitapahtuman aika \r";

    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        transact+=QString::number(json_obj["id_transactions"].toInt())+"                            ";
        transact+=QString::number(json_obj["id_account"].toInt())+"                          ";

        transact+=QString::number(json_obj["amount"].toDouble())+"      ";
        transact+=json_obj["transactionType"].toString()+"               ";
        transact+=json_obj["transactionDate"].toString()+"\r";


    }

    ui->textTransactions->setText(transact);

    reply->deleteLater();
    getManager->deleteLater();
}




