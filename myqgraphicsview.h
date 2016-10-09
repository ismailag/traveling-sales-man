#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H
#include <QGraphicsView>
    #include <QGraphicsScene>
    #include <QGraphicsEllipseItem>
    #include <QMouseEvent>

    class MyQGraphicsView : public QGraphicsView
    {
        Q_OBJECT
    public:
        explicit MyQGraphicsView(QWidget *parent = 0);

    signals:
    void boardmove(QPointF&) ;
    void boardclick(QPointF&) ;
    public slots:
        void mousePressEvent(QMouseEvent * e);

    protected :
        QGraphicsScene * scene;
    protected:
        void mouseMoveEvent(QMouseEvent *ev) ;
    public:
         QGraphicsScene* getscene() ;
         void drawline(qreal , qreal , qreal , qreal) ;
         void clearboard();
         void drawpoint(qreal, qreal) ;
    };
#endif
