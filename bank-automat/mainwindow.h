#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QLabel.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "pin.h"


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
    void showTransactions();
    void showPinDialog();
    void sendDataToServer(const QJsonObject &data);


private slots:
    void displayTagId(const QString &tagId);
    void fetchPasswordFromServer(const QString &tagId);
    void handleNetworkReply(QNetworkReply* reply);
    void handlePinVerified(bool success);
    void openPin();

private:
    Ui::MainWindow *ui;
    Rfidreader * reader;
    QLabel *statusLabel;
    QNetworkAccessManager *networkManager;
    pin * pinDialog;

};
#endif

