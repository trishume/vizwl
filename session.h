#ifndef SESSION_H
#define SESSION_H

#include <QObject>

class MainWindow;
class QIODevice;

class Session : public QObject
{
  Q_OBJECT
public:
  explicit Session(QObject *parent = 0);

signals:

public slots:
  void setConnection(QIODevice *conn);
  void canRead();

private:
  MainWindow *window;

  QIODevice *conn;
  int sentinelIndex;

  QByteArray *curFrame;

  void doFrame();
};

#endif // SESSION_H
