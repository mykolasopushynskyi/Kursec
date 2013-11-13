#include "serverconnector.h"

ServerConnector::ServerConnector(Logger *l, QObject *parent) :
    QObject(parent)
{
    textLog = l;
    _sok = new QTcpSocket(this);
}

void ServerConnector::sendData(QHostAddress* a, qint16 port, QByteArray data)
{
    _sok->connectToHost(*a ,port);

    if( _sok->waitForConnected(100)){
        _sok->write(data);
        _sok->flush();
        _sok->waitForBytesWritten(1000);
        _sok->close();
    }
    else
    {
        textLog->log("Я: Не можу під'єднатись!");
    }
}
