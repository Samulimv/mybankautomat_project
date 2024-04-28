#include "tilit.h"
#include "ui_tilit.h"
#include "mainmenu.h"

tilit::tilit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tilit)
{
    ui->setupUi(this);
}

tilit::~tilit()
{
    delete ui;
}

void tilit::getTili()
{
    QString user=QString::number(userId);
    QString site_url="http://localhost:3000/account/user/"+user;
    QNetworkRequest request((site_url));
    qDebug()<<userId;
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    Manager = new QNetworkAccessManager(this);

    connect(Manager, SIGNAL(finished (QNetworkReply*)), this, SLOT(tiliSlot(QNetworkReply*)));

    Reply = Manager->get(request);
}

void tilit::tiliSlot(QNetworkReply *)
{
    userData=Reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(userData);
    QJsonArray json_array = json_doc.array();
    firstAccountNumber=json_array.at(0)["accountNumber"].toString();
    scndAccountNumber=json_array.at(1)["accountNumber"].toString();

    ui->btn_tili_1->setText(firstAccountNumber);
    ui->btn_tili_2->setText(scndAccountNumber);



}
void tilit::setUserId(const int &newUserId)
{
    userId=newUserId;


}
void tilit::setWebToken(const QByteArray &newWebToken)
{
    webToken=newWebToken;

}

void tilit::setAccountIds(const int &newAccountId, const int &newcsndAccountId)
{
    accountId=newAccountId;
    scndAccountId=newcsndAccountId;
    qDebug()<<accountId;
    qDebug()<<scndAccountId;

}

void tilit::on_btn_tili_1_clicked()
{
    chosenAccountId=accountId;
    this->close();
    mainmenu *mainObject= new mainmenu(this);

    mainObject->show();




}


void tilit::on_btn_tili_2_clicked()
{
    chosenAccountId=scndAccountId;
    this->close();
    mainmenu *mainObject= new mainmenu(this);

    mainObject->show();
    qDebug()<<scndAccountId;



}



void tilit::on_btn_takaisin_clicked()
{
    this->close();
    mainmenu *mainObject= new mainmenu(this);
    mainObject->show();

}

