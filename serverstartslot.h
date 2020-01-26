#ifndef SERVERSTARTSLOT_H
#define SERVERSTARTSLOT_H

#include <QObject>
#include <WebServer/server.h>
#include <WebServer/jsoncontroller.h>
#include "serverstarted.h"
using namespace std;
using namespace Mongoose;
class ServerStartSlot: public QObject ,  public JsonController
{
    Q_OBJECT
public:
    explicit ServerStartSlot(QObject *parent = nullptr);
    ServerStarted myController;
    Server server;
    void Hand();
};

#endif // SERVERSTARTSLOT_H
