#include "mainwindow.h"
#include <QApplication>

#include "listener.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  Listener listener(NULL);

  return a.exec();
}
