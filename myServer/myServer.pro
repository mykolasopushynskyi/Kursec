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
        logger.cpp \
        thandler.cpp \
    checkhandler.cpp \
    errorhandler.cpp \
    transactionmanager.cpp \
    gethandler.cpp \
    puthandler.cpp \
    payhandler.cpp \
    account.cpp \
    user.cpp \
    accountmanager.cpp

HEADERS  += server.h \
            myserver.h \
            logger.h \
            thandler.h \
    checkhandler.h \
    errorhandler.h \
    transactionmanager.h \
    gethandler.h \
    puthandler.h \
    payhandler.h \
    account.h \
    user.h \
    accountmanager.h

FORMS    += server.ui
