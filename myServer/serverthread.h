#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include "myserver.h"
#include "logger.h"

class ServerThread : public QThread
{
    Q_OBJECT
public:
    ServerThread(Logger *l);

protected:
    void run();
private:
    Logger *logger;
};

#endif // SERVERTHREAD_H
