#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include "thandler.h"

//Останній клас в ланцюжку
class ErrorHandler : public THandler
{
public:
    ErrorHandler();
    QString handle(QByteArray t);
};

#endif // ERRORHANDLER_H
