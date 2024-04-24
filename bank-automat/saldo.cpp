#include "saldo.h"
#include "ui_saldo.h"
#include "QMessageBox"

saldo::saldo(QWidget *parent)
    : QDialog(parent), ui(new Ui::saldo), TManager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
    connect(ui->lopeta, &QPushButton::clicked, this, &saldo::on_lopeta_clicked);
}

saldo::~saldo() {
    delete ui;
}



void saldo::setWebToken(const QByteArray &newWebToken) {
    webToken = newWebToken;
}

void saldo::getSaldo() {

    QString site_url ="http://localhost:3000/balance/%1";
    QNetworkRequest request(site_url);

    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader("Authorization", myToken);

    connect(TManager, &QNetworkAccessManager::finished, this, &saldo::handleSaldoReply);

    TManager->get(request);

}


void saldo::on_lopeta_clicked(int id_account) {

    QString site_url = QString("http://localhost:3000/balance/%1").arg(id_account);
    QNetworkRequest request(site_url);
    QByteArray myToken = "Bearer " + webToken;
    request.setRawHeader("Authorization", myToken);
    connect(TManager, &QNetworkAccessManager::finished, this, &saldo::handleSaldoReply);

    TManager->get(request);
}

void saldo::handleSaldoReply(QNetworkReply *reply) {
    QByteArray response_data = reply->readAll();
    reply->deleteLater();

    if (reply->error() == QNetworkReply::NoError) {
        // Oletetaan, että JSON-vastauksen muoto on { "saldo": value }
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();
        double saldo = json_obj["saldo"].toDouble();
        ui->tilinsaldo->setText(QString::number(saldo, 'f', 2));
    } else {
        ui->tilinsaldo->setText("Virhe saldon haussa");
    }
}
