#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Python.h"
#include <cstdio>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_4->setText("aaaa");
}

MainWindow::~MainWindow()
{
    delete ui;
}
