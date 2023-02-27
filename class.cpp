#include<iostream>
using namespace std;
class Point
{
     public:
    int *x=nullptr;int y;
   
    Point(int &x1)
    {
        x= &x1;
        
    }
    int getx()
    {
        return *x;
    }

};

int main()
{
    int r=10;
    int e=25;
    int *t= &r;
    int *p= &e;
    
    Point *P1=new Point(r);
    Point *P2=new Point(e);
    //cout<<*(P1->x)<<" "<<P1->y<<endl;
    //cout<<*(P2->x)<<" "<<P2->y<<endl;
    cout<<P1->getx()<<"\n";
    cout<<P2->getx()<<"\n";
}