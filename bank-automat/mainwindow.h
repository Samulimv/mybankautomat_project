#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QLabel.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "pin.h"
#include "rfidreader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class RFIDReader;  // Forward declaration
class pin;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showPinDialog();
     QString returnCardNumber();

private slots:
    void displayTagId(const QString &tagId);
    void openPin();

private:
    Ui::MainWindow *ui;
    RFIDReader * reader;
    QLabel *statusLabel;
    QNetworkAccessManager *networkManager;
    pin * pinDialog;
    QString cleanedTagId;

};
#endif
