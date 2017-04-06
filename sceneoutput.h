#ifndef SCENEOUTPUT_H
#define SCENEOUTPUT_H

#include "output.h"

class QGraphicsScene;

class SceneOutput : public Output
{
public:
  explicit SceneOutput(QObject *parent = 0);
  void setScene(QGraphicsScene *scene);

  virtual void runCommand(Command command, QVector<float> &args);

private:
  QGraphicsScene *scene;
};

#endif // SCENEOUTPUT_H
