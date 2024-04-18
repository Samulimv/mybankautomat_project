#ifndef PIN_H
#define PIN_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class pin;
}

class pin : public QDialog
{
    Q_OBJECT

public:
    explicit pin(QWidget *parent = nullptr);
    ~pin();

private slots:

    void button_clicked();
    void cancel_clicked();
    void clear_clicked();
    void enter_clicked();
    void loginSlot(QNetworkReply *reply);

private:
    Ui::pin *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // PIN_H
