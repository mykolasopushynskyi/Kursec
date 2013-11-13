#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QTextEdit>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QTextEdit *l, QObject *parent = 0);
    void log(QString msg);

signals:

public slots:
private:
    QTextEdit* textEditLog;
};

#endif // LOGGER_H
