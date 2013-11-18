#include "serverconnector.h"

ServerConnector::ServerConnector(Logger *l, QObject *parent) :
    QObject(parent)
{
    textLog = l;
    _sok = new QTcpSocket();

    connect(_sok, SIGNAL(readyRead()), this, SLOT(readResponce()));
    connect(_sok, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void ServerConnector::readResponce(){
    QByteArray responce;
    responce = _sok->readAll();
    emit log("Сервер:" + responce);
    _sok->close();
    return;
}

void ServerConnector::displayError(QAbstractSocket::SocketError socketError)
{}

void ServerConnector::sendData(QHostAddress* a, qint16 port, QByteArray data)
{
    _sok->abort();
    _sok->connectToHost(*a ,port);

    if( _sok->waitForConnected()){
        _sok->write(data);
        _sok->flush();
        _sok->waitForBytesWritten();
    }
    else
    {
        textLog->log("Я: Не можу під'єднатись!");
    }
}
