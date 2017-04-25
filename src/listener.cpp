#include "listener.h"
#include <QLocalServer>
#include <QDebug>
#include <QIODevice>
#include <QLocalSocket>
#include "session.h"

Listener::Listener(QObject *parent) : QObject(parent), localServer()
{
  bool worked = localServer.listen("/var/tmp/vizwl.socket");
  if(worked) {
    qDebug() << "Listening on: " << localServer.fullServerName();
    QObject::connect(&localServer, &QLocalServer::newConnection, this, &Listener::clientConnected);
  } else {
    qDebug() << "Socket already taken";
    // TODO rm and try again
  }
}

Listener::~Listener() {
  localServer.close();
}

void Listener::clientConnected() {
  qDebug() << "Client connected.";
  Session *sess = new Session(this);
  QLocalSocket *socket = localServer.nextPendingConnection();
  sess->setConnection(dynamic_cast<QIODevice*>(socket));
  // TODO clean up session on socket close
}
