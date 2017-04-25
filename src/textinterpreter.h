#ifndef TEXTINTERPRETER_H
#define TEXTINTERPRETER_H

#include <QObject>
#include <QHash>
#include <QString>
#include "output.h"

class TextInterpreter : public QObject
{
  Q_OBJECT
public:
  explicit TextInterpreter(QObject *parent = 0);

  QByteArray *replaceFrame(QByteArray *newFrame);
signals:

public slots:
  void drawFrame(Output *out);

private:
  QByteArray *frame;
  QHash<QString, Output::Command> commandMap;
};

#endif // TEXTINTERPRETER_H
