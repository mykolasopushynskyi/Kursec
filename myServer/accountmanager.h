#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QObject>
#include <QVector>

#include "user.h"
#include "account.h"

class AccountManager : public QObject
{
    Q_OBJECT
public:
    explicit AccountManager(QObject *parent = 0);

    QString checkMoney(QString id, QString pin);
    QString getMoney(QString id, QString pin, QString va);
    QString putMoney(QString id, QString pin, QString val);
    QString payMoney(QString id, QString pin, QString val, QString id2);

signals:
public slots:
private:
    UserAccount* findAccount(QString id);
    QVector<UserAccount> accounts;
};

#endif // ACCOUNTMANAGER_H
