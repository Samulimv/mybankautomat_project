#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "transactions.h"


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
    void sendDataToServer(const QJsonObject &data);



private slots:
    void displayTagId(const QString &tagId);
    //void fetchPasswordFromServer(const QString &tagId);
    void handleNetworkReply(QNetworkReply* reply);
    void handlePinVerified(bool success);
    void openPin();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
