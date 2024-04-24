#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QApplication>
#include "rfidreader.h"
#include "pin.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showPinDialog();
    QString returnCardNumber()const;


private slots:
    void displayTagId(const QString &tagId);
    void openPin();

private:
    Ui::MainWindow *ui;

    RFIDReader * reader;
    pin * pinDialog;
    QString card;
    QString cleanedTagId;

};
#endif // MAINWINDOW_H
