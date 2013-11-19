#ifndef USER_H
#define USER_H

#include <QObject>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QString id, QString pin,QObject *parent = 0);
    bool authUser(QString pin);
signals:

public slots:
private:
     QString id;
     QString pin;
};

#endif // USER_H
