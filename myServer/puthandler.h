#ifndef PUTHANDLER_H
#define PUTHANDLER_H

#include <QXmlStreamReader>
#include <QRegExp>

#include "thandler.h"

class PutHandler : public THandler
{
public:
    PutHandler();
    QString handle(QByteArray t);
};

#endif // PUTHANDLER_H
