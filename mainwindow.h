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
  QGraphicsScene *scene;

private:
  QGraphicsView *graphicsView;
};

#endif // MAINWINDOW_H
