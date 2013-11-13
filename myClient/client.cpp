#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    //створення сокету
    textLog = new Logger(ui->message,this);

    transBuilder = new TransBuilder(textLog);
    connector = new ServerConnector(textLog);

    //підключення сигналів
    //connect(_sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
   // connect(_sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
   // connect(_sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
   // connect(_sok, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    delete ui;
}
/*
void Client::onSokDisplayError(QAbstractSocket::SocketError socketError)
{}

void Client::onSokDisconnected()
{}

void Client::onSokConnected()
{}

void Client::onSokReadyRead()
{}*/

//Запит перевірки стану рахунку
void Client::on_pushButton_3_clicked()
{
    sendData(transBuilder->checkMoney(
                ui->edtPIN->text(),
                ui->accountId->text()
                 )
             );
}

//Зняття грошей
void Client::on_pushButton_4_clicked()
{
    sendData(transBuilder->getMoney(
                 ui->edtPIN->text(),
                 ui->accountId->text(),
                 ui->moneyValue->text()
                 )
             );
}

//Поповнення рахунку
void Client::on_pushButton_5_clicked()
{
    sendData(transBuilder->putMoney(
                 ui->edtPIN->text(),
                 ui->accountId->text(),
                 ui->moneyValue->text()
                 )
             );
}

//Переведення грошей
void Client::on_pushButton_6_clicked()
{
    sendData(transBuilder->payMoney(
                 ui->edtPIN->text(),
                 ui->accountId->text(),
                 ui->moneyValue->text(),
                 ui->accountId2->text()
                 )
             );
}

//послати дані на сервер
void Client::sendData(QByteArray msg)
{
    connector->sendData(new QHostAddress(ui->addr->text()),
                        ui->port->text().toUInt(),
                        msg);
    /*

    QHostAddress* a = new QHostAddress(ui->addr->text());


    _sok->connectToHost(*a ,ui->port->text().toUInt());

    if( _sok->waitForConnected(100)){
        _sok->write(msg);
        _sok->flush();
        _sok->waitForBytesWritten(1000);
        _sok->close();
    }
    else
    {
        textLog->log("Я: Не можу під'єднатись!");
    }*/
}
