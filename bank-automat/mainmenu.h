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
    QNetworkAccessManager *mainManager;
    QNetworkReply *mainReply;
    QByteArray webToken;
    QByteArray main_data;
    QString cardNum;
    int credOrDeb;
    int accountId;
    int scndAccountId;

};

#endif // MAINMENU_H
