#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

    void setWebToken(const QByteArray &newWebToken);
    void setCardNum(const QString &newCardNum);



    void idAccount();
private slots:
    void on_tilinvalinta_clicked();
    void on_tapahtumat_clicked();
    void on_otto_clicked();
    void on_saldo_clicked();
    void on_stopmenu_clicked();
    void idAccountSlot(QNetworkReply*);



private:
    Ui::mainmenu *ui;
    QNetworkAccessManager *Manager;
    QNetworkReply *reply;
    QByteArray webToken;
    QByteArray response_data;
    QString cardNum;
    int credOrDeb;
    QString accountId;
    QString scndAccountId;

};

#endif // MAINMENU_H
