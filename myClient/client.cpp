#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    //створення сокету
    _sok = new QTcpSocket(this);
    transBuilder = new TransBuilder();

    //підключення сигналів
    connect(_sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(_sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(_sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(_sok, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    delete ui;
}


void Client::onSokDisplayError(QAbstractSocket::SocketError socketError)
{}

void Client::onSokDisconnected()
{
   // ui->grpInfo->setEnabled(false);
}

void Client::onSokConnected()
{
   /* ui->message->setText("Connected");
    _sok->write("check_money");
    _sok->flush();
    _sok->waitForBytesWritten(1000);
    _sok->close();*/
}

void Client::onSokReadyRead()
{}

//Запит перевірки стану рахунку
void Client::on_pushButton_3_clicked()
{
    QHostAddress* a = new QHostAddress(ui->addr->text());
    _sok->connectToHost(*a ,ui->port->text().toUInt());

    if( _sok->waitForConnected(100)){
        QByteArray qb = transBuilder->checkMoney(
                    ui->edtPIN->text(),
                    ui->accountId->text());
        _sok->write(qb);
        _sok->flush();
        _sok->waitForBytesWritten(1000);
        _sok->close();
    }
    else
    {
        log("Я: Не можу під'єднатись!");
    }
}

void Client::log(QString msg)
{
    ui->message->append(msg.trimmed());
}
