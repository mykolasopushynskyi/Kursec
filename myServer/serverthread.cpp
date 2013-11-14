#include "serverthread.h"

ServerThread::ServerThread(Logger *l)
{
    logger = l;

}

void ServerThread::run()
{
    new MyServer(logger);
}
