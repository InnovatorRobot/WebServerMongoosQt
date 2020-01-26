#include <QCoreApplication>
#include "serverstartslot.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ServerStartSlot *webserver = new ServerStartSlot();
    webserver->Hand();
    return a.exec();
}
