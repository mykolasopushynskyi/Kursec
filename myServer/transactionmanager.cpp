#include "transactionmanager.h"

TransactionManager::TransactionManager(QObject *parent) :
    QObject(parent)
{
    AccountManager* accountManager = new AccountManager();

    root = new CheckHandler(accountManager);
    root->add(new GetHandler(accountManager));
    root->add(new PutHandler(accountManager));
    root->add(new PayHandler(accountManager));
    root->add(new ErrorHandler(accountManager));
}

QString TransactionManager::handleTransaction(QByteArray transaction)
{
    return root->handle(transaction);
}
