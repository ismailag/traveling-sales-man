#include "points.h"

points::points()
{
    //ctor
}

void points::addpoint(point p)
{
dp.push_back(p) ;
}
deque<point> & points::getdp()
{
    return dp ;
}

void points::clear()
{
    dp.clear();
}
point points::searchpoint(int i)
{
   deque<point>::iterator it ;

        for (it=dp.begin()  ; it<dp.end(); it++ )
        {
            if (i == it->getindex() )
            {
                break ;
            }

        }
 return *it ;
}

