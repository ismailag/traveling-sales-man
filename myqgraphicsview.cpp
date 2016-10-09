#include "myqgraphicsview.h"
    #include <QPointF>

    MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
        QGraphicsView(parent)
    {
        scene = new QGraphicsScene();
        this->setSceneRect(104, 23, 350, 350);
        this->setScene(scene);
         this->scale(1, -1);
        setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    }

    void MyQGraphicsView::mousePressEvent(QMouseEvent * e)
    {
        double rad =3.8;
        QPointF pt = mapToScene(e->pos());


        if (pt.x()>=0  && pt.y()>=0)
        {
            QPen p (QColor("#7AB317"), 2.5 , Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

           scene->addEllipse(pt.x()-rad, pt.y()-rad, rad*2.0, rad*2.0,p, QBrush(QColor("#0D6759") ));


           emit boardclick(pt);}


    }

    void MyQGraphicsView::mouseMoveEvent(QMouseEvent *ev)
    {
        QPointF mousepos= mapToScene(ev->pos());

        if (mousepos.x()>=0  && mousepos.y()>=0)
        {emit boardmove(mousepos);}

    }

    QGraphicsScene* MyQGraphicsView::getscene()
    {
        return scene ;

    }

    void MyQGraphicsView::drawline(qreal x1, qreal y1 , qreal x2 , qreal y2)
    {
        QPen p (QColor("2A044A"), 2.5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

        scene->addLine(x1,y1,x2,y2,p) ;

    }

    void MyQGraphicsView::clearboard()
    {
        delete scene ;
        scene = new QGraphicsScene();
        this->setSceneRect(104, 23, 350, 350);
        this->setScene(scene);
       // setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);


    }

    void MyQGraphicsView::drawpoint( qreal x ,  qreal y)
    {
        int rad =5;
        QPen p (QColor("#7AB317"), 2.5 , Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        scene->addEllipse(x-rad, y-rad, rad*2.0, rad*2.0,p, QBrush(Qt::NoBrush));

    }
