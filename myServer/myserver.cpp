#include "myserver.h"

MyServer::MyServer(QString prt, QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    addr = new QHostAddress("127.0.0.1");
    quint16 port = prt.toInt();

    if(!server->listen(*addr,port))
    {
        emit log("Server could not start");
        isStarted = true;
    }
    else
    {
        emit log("Server started!");
        emit log("Address:" + addr->toString());
        emit log("Port:" + port);
    }
}

void MyServer::newConnection()
{
    if(isStarted)
    {
        emit log("Server started!");
        emit log("Address:" + addr->toString());
        isStarted = false;
    }

    QTcpSocket * socket = server->nextPendingConnection();
    if(socket->waitForReadyRead(3000)){
        QByteArray data = socket->readAll();

        //Обробити транзакцію
        emit log("new:" + data);
    }
    else
    {
          //logger->log("Cant read data");
    }
    socket->close();
}
