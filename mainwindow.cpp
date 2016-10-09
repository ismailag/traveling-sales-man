#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size().width(),this->size().height());

    this->connect(this->ui->board, SIGNAL(boardclick(QPointF&)), this,SLOT(getpoint(QPointF&)));
    this->connect(this->ui->board , SIGNAL(boardmove(QPointF&)) , this , SLOT(mousepos(QPointF&))) ;

    this->ui->start->setIcon(QIcon("/home/ismail/Desktop/start.png"));

    QShortcut *shortcut = new QShortcut(QKeySequence("Space"), this->ui->start);
    this->connect(shortcut, SIGNAL(activated()), this, SLOT(on_start_clicked()));
    QShortcut *shortcut2 = new QShortcut(QKeySequence("r"), this->ui->reset);
    this->connect(shortcut2, SIGNAL(activated()), this, SLOT(on_reset_clicked()));

    this->counter=0 ;
     distance = 0 ;
    this->test= false ;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::mousepos(QPointF &pos)
{
    this->ui->label_3->setText("x: "+ QString::number(pos.x())+" y: "+ QString::number(pos.y()));
}

void MainWindow::getpoint(QPointF &pos)
{
    this->ui->last->setText("last point \nx: "+ QString::number(pos.x())+" y: "+ QString::number(pos.y()));
    this->ui->lcdNumber_6->display(++counter);
    p.setpoint(pos.x(),pos.y(),counter-1) ;
    pts.addpoint(p);
    test= true ;


    //setAttribute(Qt::WA_OpaquePaintEvent);
   /* QPixmap pixmap(this->ui->label_2->width(),this->ui->label_2->height());
        pixmap.fill(QColor("transparent"));

        QPainter painter(&pixmap);
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(pos.x(), pos.y(), 10, 10);
       painter.save();
        this->ui->label_2->setPixmap(pixmap);*/
}

void MainWindow::on_start_clicked()
{





if( test )
{

matrix m(counter) ;
deque <float> temp = m.start(pts, & distance) ;
point po(pts.searchpoint(temp.front()).getx() ,pts.searchpoint(temp.front()).gety() ,0) ;
point p1(po);
temp.pop_front();
this->ui->board->clearboard();

while (! temp.empty())
    {

    this->ui->board->drawline(pts.searchpoint(temp.front()).getx() , pts.searchpoint(temp.front()).gety(),po.getx(),po.gety()) ;

    po.setpoint(pts.searchpoint(temp.front()).getx() ,pts.searchpoint(temp.front()).gety() ,0);

    this->ui->board->drawpoint(pts.searchpoint(temp.front()).getx() , pts.searchpoint(temp.front()).gety());


    temp.pop_front() ;

}
this->ui->board->drawline(p1.getx(),p1.gety(),po.getx(),po.gety()) ;
this->ui->board->drawpoint(p1.getx(),p1.gety()) ;

//distance = distance + po.distance(p1);

this->ui->distance->setText("Distance ="+ QString::number(distance));
test= false ;



}

}

void MainWindow::on_reset_clicked()
{

    counter = 0 ;
    distance=0 ;
    test=false ;
    this->ui->lcdNumber_6->display(counter);
    this->ui->last->setText("last point");
    this->ui->distance->setText("Distance =");
    pts.clear();
    this->ui->board->clearboard();
}
