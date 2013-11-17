#ifndef GETHANDLER_H
#define GETHANDLER_H

#include <QXmlStreamReader>
#include <QRegExp>

#include "thandler.h"

class GetHandler : public THandler
{
public:
    GetHandler();
    QString handle(QByteArray t);
};

#endif // GETHANDLER_H
