#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
   // logger = new Logger(ui->message);
    ui->setupUi(this);
}

Server::~Server()
{
    delete ui;
}

void Server::on_start_clicked()
{
    mServer = new MyServer(ui->port->text());
    connect(mServer, SIGNAL(log(const QString)), this, SLOT(log(const QString)));

    ui->start->setEnabled(false);
    ui->port->setEnabled(false);
    ui->address->setEnabled(false);

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)){
            ui->address->setText(address.toString());
            break;
        }
    }
}

void Server::log(const QString text)
{
    ui->message->append(text);
}
