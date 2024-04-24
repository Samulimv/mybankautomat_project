#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class saldo;
}

class saldo : public QDialog {
    Q_OBJECT

public:
    explicit saldo(QWidget *parent = nullptr);
    ~saldo();
    void setWebToken(const QByteArray &newWebToken);
    void getSaldo();

private slots:

    void handleSaldoReply(QNetworkReply *reply);
    void on_lopeta_clicked(int id_account);

private:
    Ui::saldo *ui;
    QNetworkAccessManager *TManager;
    QByteArray webToken;
};

#endif
