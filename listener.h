#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include <QLocalServer>

class QLocalServer;

class Listener : public QObject
{
  Q_OBJECT
public:
  explicit Listener(QObject *parent = 0);
  ~Listener();

signals:

public slots:
  void clientConnected();

private:
  QLocalServer localServer;
};

#endif // LISTENER_H
