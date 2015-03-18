
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zenmapqt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /home/michal/nmap/nmap/zenmap/zenmapQt/project/jni/python/Include /home/michal/nmap/nmap/zenmap/zenmapQt/project/jni/python/

ANDROID_EXTRA_LIBS += /home/michal/nmap/nmap/zenmap/zenmapQt/project/libs/armeabi/libpython2.7.so
LIBS += /home/michal/nmap/nmap/zenmap/zenmapQt/project/libs/armeabi/libpython2.7.so

CONFIG += mobility console
MOBILITY = 
