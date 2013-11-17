#include "transactionmanager.h"

TransactionManager::TransactionManager(QObject *parent) :
    QObject(parent)
{
    //TODO Add building chain here.
    root = new CheckHandler;
    root->add(new GetHandler());
    root->add(new PutHandler());
    root->add(new PayHandler());
    root->add(new ErrorHandler());
}

QString TransactionManager::handleTransaction(QByteArray transaction)
{
    return root->handle(transaction);
}
