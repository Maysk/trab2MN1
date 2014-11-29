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
            src/matrix.cpp \
            src/result.cpp\
            src/listResults.cpp \
            src/gaussTemplate.cpp \
            src/gaussJordan.cpp \
            src/gauss.cpp \
            src/dialog.cpp \
            src/mainwindow.cpp \

HEADERS  += lib/imports.h \
            lib/matrix.h \
            lib/result.h\
            lib/listResults.h \
            lib/gaussjordan.h \
            lib/gaussTemplate.h \
            lib/gauss.h \
            lib/dialog.h \
            lib/mainwindow.h \

FORMS    += mainwindow.ui\
            dialog.ui
