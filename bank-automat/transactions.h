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

private slots:
    void transactionsSlot (QNetworkReply *reply);

    void on_btnShowTrans_clicked();

private:
    Ui::transactions *ui;

    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;


};

#endif // TRANSACTIONS_H
