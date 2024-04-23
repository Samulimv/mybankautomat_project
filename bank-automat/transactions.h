#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class transactions;
}

class transactions : public QDialog
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    ~transactions();
    void setWebToken(QByteArray &newWebToken);
    void getTransactions();

private slots:




    void transactionsSlot(QNetworkReply *Treply);
    void on_btnTakaisin_clicked();

private:
    Ui::transactions *ui;
    QNetworkAccessManager *TManager;
    QByteArray tapahtumat_Data;
    QNetworkReply *Treply;
    QByteArray webToken;






};

#endif // TRANSACTIONS_H
