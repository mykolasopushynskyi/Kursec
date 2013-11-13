#include "transbuilder.h"

TransBuilder::TransBuilder(QObject *parent) :
    QObject(parent)
{
   // writer = new QXmlStreamWriter();
}

QByteArray TransBuilder::checkMoney(QString pin, QString id)
{
    QByteArray* result = new QByteArray();


    QXmlStreamWriter writer(result);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("checkMoney");
        writer.writeStartElement("id");
            writer.writeCharacters(id);
        writer.writeEndElement();

        writer.writeStartElement("pin");
            writer.writeCharacters(pin);
        writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();

    return *result;
}

QString TransBuilder::getMoney()
{
    return "";
}

QString TransBuilder::putMoney()
{
    return "";
}

QString TransBuilder::payMoney()
{
    return "";
}
