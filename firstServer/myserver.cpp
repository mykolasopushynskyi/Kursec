#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{

    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    QHostAddress* addr = new QHostAddress("127.0.0.1");
    quint16 port = 4444;

    if(!server->listen(*addr,port))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!\n\r";
        qDebug() << "Address:" << addr->toString() << "\r\n";
        qDebug() << "Port:" << port << "\r\n";
    }
}

void MyServer::newConnection()
{
    QTcpSocket * socket = server->nextPendingConnection();
    if( socket->waitForReadyRead()){
        QByteArray data = socket->readAll();
        qDebug() << "msg:" << data;
    }
    else
    {
         qDebug() << "cant read";
    }
    socket->close();
}




//Прочитати рядок
QString MyServer::readLine(QTcpSocket *socket )
{
  QString line = "";
  int bytesAvail = waitForInput( socket );
  if (bytesAvail > 0) {
    int cnt = 0;
    bool endOfLine = false;
    bool endOfStream = false;
    while (cnt < bytesAvail && (!endOfLine) && (!endOfStream)) {
      char ch;
      int bytesRead = socket->read(&ch, sizeof(ch));
      if (bytesRead == sizeof(ch)) {
        cnt++;
        line.append( ch );
        if (ch == '\r') {
          endOfLine = true;
        }
      }
      else {
        endOfStream = true;
      }
    }
  }
  return line;
}

int MyServer::waitForInput( QTcpSocket *socket )
{
  int bytesAvail = -1;
  while (socket->state() == QAbstractSocket::ConnectedState && bytesAvail < 0) {
    if (socket->waitForReadyRead( 50 )) {
      bytesAvail = socket->bytesAvailable();
    }
    else {
      QThread::msleep ( 50 ) ;
    }
  }
  return bytesAvail;
}
