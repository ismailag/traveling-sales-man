#ifndef POINT_H
#define POINT_H
#include<iostream>
#include "math.h"
using namespace std ;
class point
{
    float x ;
    float y ;
    int index ;
    public:
    point(float , float , int );
    point() ;
    float distance(point);
    float getx();
    float gety();
    int getindex() ;
    void setpoint(float, float , int ) ;
};

#endif // POINT_H
