#ifndef OTTO_H
#define OTTO_H

#include <QDialog>
#include "mainwindow.h"
#include "transactions.h"
#include "pin.h"
#include "mainmenu.h"
#include "muusumma.h"

namespace Ui {
class otto;
}

class otto : public QDialog
{
    Q_OBJECT

public:
    explicit otto(QWidget *parent = nullptr);
    ~otto();

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
};

#endif // OTTO_H
