#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "transactionmanager.h"

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QString port, QObject *parent = 0);
    QHostAddress* getAddress();
signals:
    void log(const QString text);
public slots:
    void newConnection();
private:
    TransactionManager* tManager;
    QTcpServer *server;
    bool isStarted ;
    QHostAddress* addr;
};

#endif // MYSERVER_H
