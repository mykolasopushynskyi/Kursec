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
    connect(connector, SIGNAL(log(const QString)), this, SLOT(log(const QString)));

}

Client::~Client()
{
    delete ui;
}

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
}

//послати дані на сервер
void Client::log(QString msg)
{
    ui->message->append(msg);
}
