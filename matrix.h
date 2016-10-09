#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include<deque>
#include <iostream>
#include <algorithm>
#include "points.h"
#include <iostream>
using namespace std;

class matrix
{
    vector<vector<float> > mat ;
    int n ;
    public:
    matrix(int);

    void setmatrix (int , int , float) ;
    float getmatrix(int , int ) ;
    friend ostream& operator<<(ostream& , matrix ) ;
    void add () ;
    float suiv(float i) ;

    float getdistance(deque<float>) ;
    deque<float> opt(deque<float>, float *dist);
     void two_swap(int , int , deque<float> & ) ;
     deque<float> algo(float *distance) ;
    deque<float> start(points, float *distance) ;
};

#endif // MATRIX_H
