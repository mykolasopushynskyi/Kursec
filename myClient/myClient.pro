#-------------------------------------------------
#
# Project created by QtCreator 2013-11-11T20:58:58
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = myClient
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    transbuilder.cpp \
    logger.cpp \
    serverconnector.cpp

HEADERS  += client.h \
    transbuilder.h \
    logger.h \
    serverconnector.h

FORMS    += client.ui
