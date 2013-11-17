#ifndef CHECKHANDLER_H
#define CHECKHANDLER_H
#include "thandler.h"
#include <QXmlStreamReader>
#include <QRegExp>

class CheckHandler : public THandler
{
public:
    CheckHandler();
    QString handle(QByteArray t);
};

#endif // CHECKHANDLER_H
