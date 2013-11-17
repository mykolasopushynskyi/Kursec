#include "thandler.h"

THandler::THandler(QObject *parent) :
    QObject(parent)
{
    next = 0;
}

void THandler::setNext(THandler* next)
{
    this->next = next;
}
void THandler::add(THandler* last)
{
    if(next)
    {
        next->add(last);
    }
    else
    {
        next = last;
    }
}

QString THandler::handle(QByteArray t)
{
    return next->handle(t);
}

