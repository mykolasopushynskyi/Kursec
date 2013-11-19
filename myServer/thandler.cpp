#include "thandler.h"

THandler::THandler(AccountManager* accountManager, QObject *parent) :
    QObject(parent)
{
    this->accountManager =  accountManager;
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

