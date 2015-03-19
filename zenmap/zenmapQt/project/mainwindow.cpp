#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Python.h"
#include <cstdio>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMetaObject::connectSlotsByName(this);

    ui->textBrowser->setText("Don't mind the UI - in final version QtQuick will be used.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scan_clicked() {
    // This is not too elegent nor safe, but final version will use PySide.
    PyObject* module = NULL;
    PyObject* func = NULL;
    PyObject *arglist;

    module = PyImport_ImportModule("scanner");
    if(module == NULL) {
        printf("failed to import scanner\n");
        abort();
    }
    func = PyObject_GetAttrString(module, "scan");
    if(func == NULL) {
        printf("failed to getattr\n");
        abort();
    }
    QByteArray ip = this->ui->ip->text().toLocal8Bit();
    arglist = Py_BuildValue("(s)", ip.data());
    PyObject* s = PyEval_CallObject(func, arglist);
    printf("called scan()\n");
    const char* data = PyString_AsString(s);
    this->ui->textBrowser->setText(data);
}
