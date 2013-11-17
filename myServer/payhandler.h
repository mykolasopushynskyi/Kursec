#ifndef PAYHANDLER_H
#define PAYHANDLER_H

#include <QXmlStreamReader>
#include <QRegExp>

#include "thandler.h"

class PayHandler : public THandler
{
public:
    PayHandler();
    QString handle(QByteArray t);
};

#endif // PAYHANDLER_H
