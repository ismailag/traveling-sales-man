#include "point.h"

point::point(float a , float b , int i )
{
    index=i ;
    x=a ;
    y=b ;
}
point::point()
{

}

float point::distance(point p1 )
{
    return sqrt(pow(( p1.x-x ), 2) + pow((p1.y-y),2)) ;
}
float point::getx()
{
    return x ;
}
float point::gety()
{
    return y ;
}
int point::getindex()
{
    return index ;
}
void point::setpoint(float a , float b , int i)
{
    index=i;
    x=a ;
    y=b;
}
