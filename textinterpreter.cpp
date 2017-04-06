#include "textinterpreter.h"

#include <QtGlobal>
#include <QTextStream>
#include <QHash>
#include <QString>
#include <QVector>
#include <QStringList>

TextInterpreter::TextInterpreter(QObject *parent) : QObject(parent), commandMap()
{
  commandMap["line"] = Output::line;
  commandMap["rect"] = Output::rectangle;
}

void TextInterpreter::drawFrame(Output *out) {
  Q_ASSERT(frame != NULL);

  QTextStream stream(frame);
  QString line;
  QVector<float> args;
  while(stream.readLineInto(&line)) {
    QStringList parts = line.split(" ", QString::SkipEmptyParts);
    if(parts.length() < 1) continue; // TODO do error
    if(!commandMap.contains(parts.at(0))) continue;
    Output::Command command = commandMap[parts.at(0)];

    args.clear();
    for(int i = 1; i < parts.length(); i++) {
      args.push_back(parts.at(i).toFloat());
    }

    out->runCommand(command, args);
  }
}

QByteArray *TextInterpreter::replaceFrame(QByteArray *newFrame) {
  QByteArray *oldFrame = frame;
  frame = newFrame;
  return oldFrame;
}
