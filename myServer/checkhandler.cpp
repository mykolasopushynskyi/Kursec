#include "checkhandler.h"

CheckHandler::CheckHandler()
{
}

QString CheckHandler::handle(QByteArray t)
{
    return THandler::handle(t);
}
