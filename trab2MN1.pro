#-------------------------------------------------
#
# Project created by QtCreator 2014-11-18T19:32:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trab2MN1
TEMPLATE = app


SOURCES +=  src/main.cpp\
            src/mainwindow.cpp \
            src/matrix.cpp \
            src/gauss.cpp \
            src/listResults.cpp \
            src/result.cpp\
            src/dialog.cpp

HEADERS  += lib/mainwindow.h \
            lib/imports.h \
            lib/matrix.h \
            lib/listResults.h \
            lib/gauss.h \
            lib/result.h\
            lib/dialog.h

FORMS    += mainwindow.ui\
            dialog.ui
