#ifndef THANDLER_H
#define THANDLER_H

#include <QObject>
#include "accountmanager.h"

//Transaction handler
class THandler : public QObject
{
    Q_OBJECT
    THandler *next;

public:
    explicit THandler(AccountManager* accountManager, QObject *parent = 0);
    void setNext(THandler *n);
    void add(THandler *n);
    virtual QString handle(QByteArray t);
signals:

public slots:

protected:
    AccountManager* accountManager;

};

#endif // THANDLER_H
