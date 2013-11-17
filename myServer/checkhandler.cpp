#include "checkhandler.h"

CheckHandler::CheckHandler()
{
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<checkMoney>
    <id>12</id>
    <pin>12</pin>
</checkMoney>
*/
QString CheckHandler::handle(QByteArray t)
{
    QXmlStreamReader* reader = new QXmlStreamReader(t);
    QXmlStreamReader::TokenType token;

    QString pin;
    QString id;

    QRegExp pinr("(\\d{4,4})");
    QRegExp idr("(\\d{5,10})");

    while(!reader->atEnd() && !reader->hasError())
    {
        token = reader->readNext();
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }

        if(token == QXmlStreamReader::StartElement) {
            if(reader->name() == "checkMoney")
            {
                continue;
            }
            else if(reader->name() == "pin")
            {
                reader->readNext();
                pin = reader->text().toString();
                continue;
            }
            else if(reader->name() == "id")
            {
                reader->readNext();
                id = reader->text().toString();
                continue;
            }
            else
            {
                return THandler::handle(t);
            }
        }
    }
    if(reader->hasError()) {
        return "Помилка в транзакції перевірки стану рахунку.";
    }

    //Перевірка валідності полів
    if(!pinr.exactMatch(pin)){
        return "Помилка запису пін коду";
    }

    if(!idr.exactMatch(id)){
        return "Помилка запису id рахунку";
    }

    //TODO Додати звертання до БД з разунками

    return "Перевірка стану рахунку пін " + pin + " id " + id;
}
