#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    QString readLine(QTcpSocket *socket);
    int waitForInput(QTcpSocket *socket);
signals:

public slots:
    void newConnection();
private:
    QTcpServer *server;

};

#endif // MYSERVER_H
