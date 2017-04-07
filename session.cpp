#include "session.h"

#include <QIODevice>
#include <QByteArray>
#include <QDebug>
#include <QGraphicsScene>

#include "textinterpreter.h"
#include "sceneoutput.h"
#include "mainwindow.h"

static const char *kSentinel = "\nframe\n";
static const int kSentinelLen = 7;

Session::Session(QObject *parent) : QObject(parent), curFrame(NULL), sentinelIndex(1), window(NULL)
{
  curFrame = new QByteArray();
  window = new MainWindow(NULL);
  window->show();
}

void Session::setConnection(QIODevice *conn) {
  this->conn = conn;
  QObject::connect(conn, &QIODevice::readyRead, this, &Session::canRead);
}

void Session::canRead() {
  char c;
  while(1) {
    bool worked = conn->getChar(&c);
    if(!worked) break;

    // add char to frame buffer
    curFrame->append(c);

    // check for end of frame
    if(c == kSentinel[sentinelIndex]) {
      sentinelIndex++;
      if(sentinelIndex >= kSentinelLen) {
        doFrame();
        sentinelIndex = 1; // don't need a newline
      }
    } else {
      sentinelIndex = 0;
    }
  }
  qDebug() << "bytes read. Cur frame size:" << curFrame->length();
}

void Session::doFrame() {
  qDebug() << "doing frame of size" << curFrame->length();
  TextInterpreter interp(this);
  interp.replaceFrame(curFrame);

//  window->scene->clear();
  SceneOutput output(this);
  interp.drawFrame(dynamic_cast<Output*>(&output));
  delete curFrame;
  window->setNewScene(output.scene);

  curFrame = new QByteArray();
}
