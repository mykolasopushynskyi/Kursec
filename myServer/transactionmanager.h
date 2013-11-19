#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <QObject>
#include "thandler.h"
#include "checkhandler.h"
#include "errorhandler.h"
#include "gethandler.h"
#include "puthandler.h"
#include "payhandler.h"
#include "accountmanager.h"


//TODO include handles here

class TransactionManager : public QObject
{
    Q_OBJECT
public:
    explicit TransactionManager(QObject *parent = 0);
    QString handleTransaction(QByteArray  transaction);
signals:

public slots:

private:
    CheckHandler* root;
    AccountManager* accountManager;
};

#endif // TRANSACTIONMANAGER_H
