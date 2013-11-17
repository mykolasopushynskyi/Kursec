#include "gethandler.h"

GetHandler::GetHandler()
{
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<getMoney>
    <id>12345</id>
    <pin>1245</pin>
    <val>12</val>
</getMoney>
*/

QString GetHandler::handle(QByteArray t)
{
    QXmlStreamReader* reader = new QXmlStreamReader(t);
    QXmlStreamReader::TokenType token;

    QString pin;
    QString id;
    QString val;

    QRegExp pinr("(\\d{4,4})");
    QRegExp idr("(\\d{5,10})");
    QRegExp valr("(\\d{1,5})");

    while(!reader->atEnd() && !reader->hasError())
    {
        token = reader->readNext();
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }

        if(token == QXmlStreamReader::StartElement) {
            if(reader->name() == "getMoney")
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
            else if(reader->name() == "val")
            {
                reader->readNext();
                val = reader->text().toString();
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
    if(!valr.exactMatch(val)){
        return "Помилка запису кількості грошей";
    }
    if(val.toUInt() == 0 ){
        return "Неправильна кількість грошей";
    }
    if(val.toInt() % 5 != 0){
        return "Сума повинна бути кратна 5 грн.";
    }

    //TODO Додати звертання до БД з разунками

    return "Зняття грошей пін " + pin + " id " + id + " val " + val;
}
