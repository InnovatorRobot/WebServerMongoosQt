QT -= gui
QT += sql core
CONFIG += c++11 console
CONFIG -= app_bundle
LIBS += -ljsoncpp
INCLUDEPATH = /usr/include/jsoncpp/
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        WebServer/controller.cpp \
        WebServer/jsoncontroller.cpp \
        WebServer/jsonresponse.cpp \
        WebServer/mongoose.cpp \
        WebServer/mutex.cpp \
        WebServer/request.cpp \
        WebServer/response.cpp \
        WebServer/server.cpp \
        WebServer/session.cpp \
        WebServer/sessions.cpp \
        WebServer/streamresponse.cpp \
        WebServer/uploadfile.cpp \
        WebServer/utils.cpp \
        WebServer/webcontroller.cpp \
        WebServer/websocket.cpp \
        WebServer/websockets.cpp \
        main.cpp \
        serverstarted.cpp \
        serverstartslot.cpp

TRANSLATIONS += \
    WebServerMongoos_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    WebServer/controller.h \
    WebServer/jsoncontroller.h \
    WebServer/jsonresponse.h \
    WebServer/mongoose.h \
    WebServer/mutex.h \
    WebServer/request.h \
    WebServer/requesthandler.h \
    WebServer/response.h \
    WebServer/server.h \
    WebServer/session.h \
    WebServer/sessions.h \
    WebServer/streamresponse.h \
    WebServer/uploadfile.h \
    WebServer/utils.h \
    WebServer/webcontroller.h \
    WebServer/websocket.h \
    WebServer/websockets.h \
    serverstarted.h \
    serverstartslot.h
