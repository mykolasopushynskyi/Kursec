#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>

#include "logger.h"
#include "transbuilder.h"
#include "serverconnector.h"

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

    void sendData(QByteArray msg);

private slots:
    /*
    //определим слоты для обработки сигналов сокета
        void onSokConnected();
        void onSokDisconnected();
    //сигнал readyRead вызывается, когда сокет получает пакет (который может быть лишь частью отправленых данных) байтов
        void onSokReadyRead();
        void onSokDisplayError(QAbstractSocket::SocketError socketError);
        */
        void log(const QString text);

        void on_pushButton_3_clicked();
        void on_pushButton_4_clicked();
        void on_pushButton_5_clicked();
        void on_pushButton_6_clicked();

private:
    TransBuilder* transBuilder;
    ServerConnector* connector;
    Ui::Client *ui;
    Logger* textLog;
    quint16 _blockSize;
};

#endif // CLIENT_H
