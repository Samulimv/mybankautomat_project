#ifndef PIN_H
#define PIN_H

#include <QDialog>

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

private:
    Ui::pin *ui;
};

#endif // PIN_H
