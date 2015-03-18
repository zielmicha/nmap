#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Python.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Py_Initialize();
    PyRun_SimpleString("print >>open('/sdcard/foo.txt', 'w'), 'Python running'");
    Py_Finalize();

    ui->label_4->setText("aaaa");
}

MainWindow::~MainWindow()
{
    delete ui;
}
