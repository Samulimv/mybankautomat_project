#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QLabel.h"
#include <QMainWindow>
<<<<<<< HEAD
#include <QSerialPort>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "pin.h"

=======
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
>>>>>>> 260d6aef8108fd1cc5db7e0573321cb19adbff30

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Rfidreader;  // Forward declaration
class pin;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showPinDialog();
    static QString returnCardNumber();

private slots:
    void displayTagId(const QString &tagId);
    void openPin();




private slots:



    void on_btnLogin_clicked();
    void loginSlot(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
    Rfidreader * reader;
    QLabel *statusLabel;
    QNetworkAccessManager *networkManager;
    pin * pinDialog;
    QString cleanedTagId;


=======
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
>>>>>>> 260d6aef8108fd1cc5db7e0573321cb19adbff30
};
#endif

