#ifndef POINTS_H
#define POINTS_H
#include "point.h"
#include<deque>
class points
{   deque <point> dp ;
    public:
    points();
    void addpoint(point);
    point searchpoint(int) ;
    deque<point> & getdp() ;
   void clear() ;
};

#endif // POINTS_H
