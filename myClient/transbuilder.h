#ifndef TRANSBUILDER_H
#define TRANSBUILDER_H

#include <QObject>
#include <QXmlStreamWriter>
#include "logger.h"

class TransBuilder : public QObject
{
    Q_OBJECT
public:
    explicit TransBuilder(Logger* l, QObject *parent = 0);

    QByteArray checkMoney(QString pin, QString id);
    QByteArray getMoney(QString pin, QString id, QString val);
    QByteArray putMoney(QString pin, QString id, QString val);
    QByteArray payMoney(QString pin, QString id, QString val, QString id2);

signals:

public slots:

private:
    QXmlStreamWriter writer;
    Logger* logger;
};

#endif // TRANSBUILDER_H
