#include "mainwindow.h"
#include <QApplication>
#include "Python.h"
#include <unistd.h>

extern "C" void dounzip();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    freopen("/sdcard/python-out.txt", "a", stdout);
    freopen("/sdcard/python-out.txt", "a", stderr);

    setvbuf(stdout, NULL, _IOLBF, 0);
    setvbuf(stderr, NULL, _IOLBF, 0);

    char cwd[128];
    getcwd(cwd, sizeof(cwd));

    setenv("PYTHONHOME", cwd, true);

    char* pythonpath = (char*)malloc(strlen(cwd) + 100);
    sprintf(pythonpath, "%s/lib/python2.7", cwd);
    setenv("PYTHONPATH", pythonpath, true);

    dounzip();

    Py_Initialize();
    PyRun_SimpleString("print 'Python running'");
    PyRun_SimpleString("import main");

    return a.exec();
}
