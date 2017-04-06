#include "sceneoutput.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

SceneOutput::SceneOutput(QObject *parent): Output(parent), scene(scene)
{

}

void SceneOutput::setScene(QGraphicsScene *scene) {
  this->scene = scene;
}

void SceneOutput::runCommand(Output::Command command, QVector<float> &args) {
  switch(command){
    case Command::line:
  {
      if(args.length() < 4) break;
      qDebug() << "line";
      QGraphicsLineItem *item = new QGraphicsLineItem(args[0],args[1],args[2],args[3]);
      scene->addItem(item); // TODO leak
  }
      break;
    case Command::rectangle:
      if(args.length() < 4) break;
      qDebug() << "rect";
      scene->addRect(args[0],args[1],args[2],args[3]);
      break;
  }
}
