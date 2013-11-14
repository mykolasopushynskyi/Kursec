#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QString port, QObject *parent = 0);
signals:
    void log(const QString text);
public slots:
    void newConnection();
private:
    QTcpServer *server;
    bool isStarted = false;
    QHostAddress* addr;
};

#endif // MYSERVER_H
