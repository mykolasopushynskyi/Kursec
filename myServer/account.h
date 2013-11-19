#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "user.h"

class UserAccount
{

public:
    UserAccount(){}
    UserAccount(User* owner, QString id, unsigned long sum);

    void add(unsigned long sum);
    long get(unsigned long sum);
    bool canGet(unsigned long sum);
    long obtainSum();
    QString getId();
    bool checkPin(QString pin);

private:
    QString id;
    unsigned long  sum;
    User* owner;
};


#endif // ACCOUNT_H
