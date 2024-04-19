#ifndef MUUSUMMA_H
#define MUUSUMMA_H

#include <QDialog>
#include "mainwindow.h"
#include "transactions.h"
#include "pin.h"
#include "mainmenu.h"
#include "otto.h"

namespace Ui {
class muusumma;
}

class muusumma : public QDialog
{
    Q_OBJECT

public:
    explicit muusumma(QWidget *parent = nullptr);
    ~muusumma();

private slots:
    void on_muusummaback_clicked();
    void on_muusummaenter_clicked();
    void on_button_clicked();

private:
    Ui::muusumma *ui;
};

#endif // MUUSUMMA_H
