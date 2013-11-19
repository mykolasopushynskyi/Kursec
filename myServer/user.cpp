#include "user.h"

User::User(QString id, QString pin, QObject *parent) :
    QObject(parent)
{
    this->id = id;
    this->pin = pin;
}

bool User::authUser(QString pin)
{
    return this->pin == pin;
}
