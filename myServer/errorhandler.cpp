#include "errorhandler.h"

ErrorHandler::ErrorHandler(AccountManager* accountManager):THandler(accountManager)
{
}

QString ErrorHandler::handle(QByteArray t)
{
    return "Неочікувана помилка!";
}
