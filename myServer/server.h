#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QThread>
#include "myserver.h"
#include "logger.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private slots:
    void on_start_clicked();
    void log(const QString text);

private:
    Ui::Server *ui;
   // Logger* logger;
    MyServer* mServer;
};

#endif // SERVER_H
