#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    //определим слоты для обработки сигналов сокета
        void onSokConnected();
        void onSokDisconnected();
    //сигнал readyRead вызывается, когда сокет получает пакет (который может быть лишь частью отправленых данных) байтов
        void onSokReadyRead();
        void onSokDisplayError(QAbstractSocket::SocketError socketError);
        
        void on_pushButton_3_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *_sok; //сокет
    quint16 _blockSize;
};

#endif // CLIENT_H
