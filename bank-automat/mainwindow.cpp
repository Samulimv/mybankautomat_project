#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pinDialog = new pin(this);

    connect(ui->pinDialog, &QPushButton::clicked, this, &MainWindow::openPinDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPinDialog()
{
    pinDialog->show();
}
