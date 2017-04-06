#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  scene = new QGraphicsScene(this);
  scene->setBackgroundBrush(QBrush(QColor(255,0,0)));

  graphicsView = new QGraphicsView(this);
  graphicsView->setScene(scene);

  this->setCentralWidget(graphicsView);
}

MainWindow::~MainWindow()
{

}
