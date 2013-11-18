#ifndef SERVERCONNECTOR_H
#define SERVERCONNECTOR_H

#include <QObject>
#include <QTcpSocket>
#include "logger.h"

class ServerConnector : public QObject
{
    Q_OBJECT
public:
    explicit ServerConnector(Logger *l, QObject *parent = 0);
    void sendData(QHostAddress* a, qint16 port, QByteArray data);
signals:
    void log(const QString text);
private slots:
    void readResponce();
    void displayError(QAbstractSocket::SocketError socketError);
private:
    QTcpSocket *_sok; //сокет
    Logger *textLog;
};

#endif // SERVERCONNECTOR_H
