#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMouseEvent>
#include<QEvent>
#include <QMainWindow>
#include <QtGui>
#include<QtCore>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "matrix.h"
#include "point.h"
#include "points.h"
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

void mousepos(QPointF &pos) ;
void getpoint(QPointF &pos) ;

void on_start_clicked();
void on_reset_clicked();

private:
   Ui::MainWindow *ui;
   int counter ;
   point p ;
   points pts ;
   bool test ;
   float distance  ;
};

#endif // MAINWINDOW_H
