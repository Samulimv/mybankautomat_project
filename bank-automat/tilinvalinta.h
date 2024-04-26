#ifndef TILINVALINTA_H
#define TILINVALINTA_H

#include <QDialog>

namespace Ui {
class tilinvalinta;
}

class tilinvalinta : public QDialog
{
    Q_OBJECT

public:
    explicit tilinvalinta(QWidget *parent = nullptr);
    ~tilinvalinta();

private slots:
    void on_takaisin_clicked();

    void on_debit_clicked();

    void on_credit_clicked();

private:
    Ui::tilinvalinta *ui;
};

#endif // TILINVALINTA_H
