#ifndef TRANSBUILDER_H
#define TRANSBUILDER_H

#include <QObject>
#include <QXmlStreamWriter>

class TransBuilder : public QObject
{
    Q_OBJECT
public:
    explicit TransBuilder(QObject *parent = 0);

    QByteArray checkMoney(QString pin, QString id);
    QString getMoney();
    QString putMoney();
    QString payMoney();

signals:

public slots:

private:
    QXmlStreamWriter writer;
};

#endif // TRANSBUILDER_H
