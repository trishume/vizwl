#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), scene(NULL)
{
  graphicsView = new QGraphicsView(this);
  graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
  graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
  graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
  graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
  graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
  graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
//  graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);


  this->setCentralWidget(graphicsView);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setNewScene(QGraphicsScene *scene) {
  if(this->scene) delete this->scene;
  this->scene = scene;

  // we want our scene to include 0,0
  QRectF sceneRect = scene->sceneRect();
  graphicsView->setSceneRect(sceneRect.united(QRectF(0,0,1,1))); // TODO window bounds

  graphicsView->setScene(scene);
}
