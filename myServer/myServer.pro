#-------------------------------------------------
#
# Project created by QtCreator 2013-11-14T21:04:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = myServer
TEMPLATE = app


SOURCES += main.cpp \
        server.cpp \
        myserver.cpp \
        logger.cpp

HEADERS  += server.h \
            myserver.h \
            logger.h

FORMS    += server.ui
