#include "logger.h"

Logger::Logger(QTextEdit *l, QObject *parent) :
    QObject(parent)
{
    textEditLog = l;
}

void Logger::log(QString msg)
{
    textEditLog->append(msg);
}
