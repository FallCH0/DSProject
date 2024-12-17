#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DrawPlace->setStyleSheet("background-color:white");
}

MainWindow::~MainWindow()
{
    delete ui;
}
