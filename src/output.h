#ifndef OUTPUT_H
#define OUTPUT_H

#include <QObject>
#include <QVector>

class Output : public QObject
{
  Q_OBJECT
public:
  explicit Output(QObject *parent = 0);

  enum Command {
    line,
    rectangle,
  };

signals:

public slots:
  virtual void runCommand(Command command, QVector<float> &args) = 0;
};

#endif // OUTPUT_H
