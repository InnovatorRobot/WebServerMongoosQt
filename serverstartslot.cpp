#include "serverstartslot.h"

ServerStartSlot::ServerStartSlot(QObject *parent) : QObject(parent)
{

}

void ServerStartSlot::Hand()
{
    srand(time(NULL));
    server.registerController(&myController);
    server.setOption("enable_directory_listing", "false");
    server.start();
    myController.dumpRoutes();
}
