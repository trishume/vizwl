#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void setNewScene(QGraphicsScene *scene);
private:
  QGraphicsView *graphicsView;
  QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
