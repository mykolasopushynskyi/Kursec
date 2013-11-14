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
}

void Server::log(const QString text)
{
    ui->message->append(text);
}
