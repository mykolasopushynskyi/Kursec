#include "transbuilder.h"

TransBuilder::TransBuilder(Logger* l, QObject *parent) :
    QObject(parent)
{
    logger = l;
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

QByteArray TransBuilder::getMoney(QString pin, QString id, QString val)
{
    QByteArray* result = new QByteArray();

    QXmlStreamWriter writer(result);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("getMoney");
        writer.writeStartElement("id");
            writer.writeCharacters(id);
        writer.writeEndElement();

        writer.writeStartElement("pin");
            writer.writeCharacters(pin);
        writer.writeEndElement();

        writer.writeStartElement("val");
            writer.writeCharacters(val);
        writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();

    return *result;
}

QByteArray TransBuilder::putMoney(QString pin, QString id, QString val)
{
    QByteArray* result = new QByteArray();

    QXmlStreamWriter writer(result);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("putMoney");
        writer.writeStartElement("id");
            writer.writeCharacters(id);
        writer.writeEndElement();

        writer.writeStartElement("pin");
            writer.writeCharacters(pin);
        writer.writeEndElement();

        writer.writeStartElement("val");
            writer.writeCharacters(val);
        writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();

    return *result;
}

QByteArray TransBuilder::payMoney(QString pin, QString id, QString val, QString id2)
{
    QByteArray* result = new QByteArray();

    QXmlStreamWriter writer(result);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("payMoney");
        writer.writeStartElement("id");
            writer.writeCharacters(id);
        writer.writeEndElement();

        writer.writeStartElement("pin");
            writer.writeCharacters(pin);
        writer.writeEndElement();

        writer.writeStartElement("val");
            writer.writeCharacters(val);
        writer.writeEndElement();

        writer.writeStartElement("id2");
            writer.writeCharacters(id2);
        writer.writeEndElement();

    writer.writeEndElement();
    writer.writeEndDocument();

    return *result;
}
