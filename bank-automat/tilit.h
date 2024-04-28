#ifndef TILIT_H
#define TILIT_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class tilit;
}

class tilit : public QDialog
{
    Q_OBJECT

public:
    explicit tilit(QWidget *parent = nullptr);
    ~tilit();

    void setUserId(const int &newUserId);
    void getTili();
    void setWebToken(const QByteArray &newWebToken);
    void setAccountIds(const int &newAccountId, const int &newcsndAccountId);

    int chosenAccountId;

private slots:
    void tiliSlot(QNetworkReply*);
    void on_btn_tili_1_clicked();

    void on_btn_tili_2_clicked();

    void on_btn_takaisin_clicked();

private:
    Ui::tilit *ui;
    int userId;
    QNetworkAccessManager* Manager;
    QNetworkReply* Reply;
    QByteArray webToken;
    QByteArray userData;
    QString firstAccountNumber;
    QString scndAccountNumber;
    int accountId;
    int scndAccountId;


};

#endif // TILIT_H
