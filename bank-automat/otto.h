#ifndef OTTO_H
#define OTTO_H

#include <QDialog>


namespace Ui {
class otto;
}

class otto :public QDialog
{
    Q_OBJECT

public:
    explicit otto(QWidget *parent = nullptr);
    ~otto();

    void setWebToken(const QByteArray &newWebToken);

    void setAccountId(const QString &newAccountId);
    void otto_clickHandler();

private slots:

    void on_otto20_clicked();
    void on_otto40_clicked();
    void on_otto60_clicked();
    void on_otto90_clicked();
    void on_otto140_clicked();
    void on_otto240_clicked();
    void on_muusumma_clicked();
    void on_alkuun_clicked();

private:
    Ui::otto *ui;
    QByteArray webToken;
    QString accountId;
    int maara;

};

#endif // OTTO_H
