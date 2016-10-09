#include "matrix.h"

matrix::matrix(int a)
{
    n=a ;
    mat.resize( n , vector<float>( n , 0 ) );
}
void matrix::setmatrix(int l , int c , float val )
{
    mat[l][c]=val ;
}
float matrix::getmatrix(int l , int c)
{
    return mat[l][c] ;
}
void matrix::add()
{
    n++ ;
    for ( int i=0 ; i<n-1 ; i++ )
    {
        cout<<"donner mat["<<i<<"]["<<n-1<<"]" ;
        float val ;
        cin>>val;
        mat[i].push_back(val);
    }
    vector<float> temp ;
    for (int i=0 ; i<n ; i++)
    {

        cout<<"donner mat["<<n-1<<"]["<<i<<"]" ;
        float val ;
        cin>>val;
        temp.push_back(val);
    }
    mat.push_back(temp);
}

float matrix::suiv(float i)
{
    if (i==n-1)
        {
            return 0 ;
        }
     else
     {
         return i+1 ;
    }
}

float matrix::getdistance(deque<float> tempp )
{
    float d=0 ;
    int j = tempp.front();
    int w=j ;

    for (int i=1 ;i<n ; i++)
    {d=mat[tempp[i]][j]+d ;
    j=tempp[i];
    }
    return mat[j][w] + d ;
}

void matrix::two_swap(int i, int j, deque<float> & temp)
{
    if (i==n-1)
    {
        int x=temp[n-1];
    temp[n-1]=temp[0] ;
    temp[0]=x;
    return ;
    }
    while(i < j)
     {
       int x = temp[i];
       temp[i] = temp[j];
       temp[j] = x;
       i++;
       j--;
     }


}

deque<float> matrix::opt(deque<float> temp , float*dist )
{
    float best_distance = getdistance(temp) ;
       deque<float> best_tour  ;
        best_tour=temp ;

    int improve=0 ;
      while (improve < 2)
    {


    for ( int i=0 ; i<n  ; i++)
    { bool test=false ;
        if (i==n-1)
        {
            test=true ;
        }

        for ( int j = i + 1; j<n || test; j++ )
        {
                test=false ;

            two_swap(i,j,temp) ;
             if (getdistance(temp)<best_distance)
                {
                    best_tour=temp ;
                    best_distance=getdistance(temp);
                    improve=0 ;
                }
               else
             {
                two_swap(i,j,temp) ;
             }
            }
        }
    improve++ ;
    }
   *dist=best_distance ;
    return(best_tour) ;}

ostream& operator<<(ostream& out , matrix m )
{
    for (int i=0 ; i<m.n ; i++)
    {
        for (int j=0 ; j<m.n ; j++ )
        {

            out<<m.mat[i][j]<<" " ;

        }
        out<<endl ;
    }
    return out ;
}

deque <float> matrix::algo(float *distance)
{
    deque <float> temp ;
    vector <float> v ;
    for (int i=1 ; i<n ; i++)
    {
        v.push_back(i) ;
    }
    int u=0 ;
    int k=0 ;
    temp.push_back(u) ;
    while (!v.empty())
    {
        float minm=5000000 ;

        for (int i=0 ; i<n ; i++)
        {

            if(std::find(temp.begin(), temp.end(), i)==temp.end())
            {
                if (mat[u][i]<=minm)
                {
                    minm=mat[u][i] ;
                    k=i ;

                }
            }
        }

        temp.push_back(k);
        u=k ;
        v.erase(remove(v.begin(), v.end(), u), v.end());
    }


    temp=opt(temp,distance) ;
    return (temp) ;
}
deque<float> matrix::start(points d, float*distance)
{
    deque<point>temp=d.getdp() ;
    deque<point>::iterator it ;
    while(!temp.empty())
    {
        for (it= temp.begin()  ; it<temp.end(); it++ )
        {
            setmatrix (temp.front().getindex(),it->getindex(),temp.front().distance(*it)) ;
            setmatrix (it->getindex(),temp.front().getindex(),temp.front().distance(*it)) ;
        }

        temp.pop_front() ;
    }
    return(algo( distance )) ;
}
