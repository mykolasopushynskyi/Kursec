#include "account.h"

UserAccount::UserAccount( User* owner, QString id, unsigned long sum)
{
    this->owner = owner;
    this->id = id;
    this->sum = sum;
}


void UserAccount::add(unsigned long sum)
{
    this->sum = this->sum + sum;
}

long UserAccount::get(unsigned long sum)
{
    if(canGet(sum))
    {
        this->sum = this->sum - sum;
        return sum;
    }
    else
    {
        return 0;
    }
}

bool UserAccount::canGet( unsigned long sum)
{
    return this->sum >= sum;
}

long UserAccount::obtainSum()
{
    return sum;
}

QString UserAccount::getId()
{
    return id;
}

bool UserAccount::checkPin(QString pin)
{
    return owner->authUser(pin);
}
