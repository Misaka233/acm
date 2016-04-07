#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
double h1,h2,d1,d2,a,b;
double e=1e-10;
inline bool f(double x)
{
    double y=h1-a*x*x;
    if(x<-e||x>d2+e) return false;
    if(y<-e) return false;
   if(x>d1)
    {
        return h1-a*d1*d1>h2-e;
    }
    else
    {
        return -b*(d1-x)*(d1-x)+y>h2-e;
    }
}
int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf",&h1,&h2,&d1,&d2,&a,&b))
    {
        double xx1=(b*d2-sqrt(b*h1+a*h1-a*b*d2*d2))/(a+b);
        double xx2=(b*d2+sqrt(b*h1+a*h1-a*b*d2*d2))/(a+b);

        if(f(xx1)||f(xx2))
        {
            cout<<"Yes"<<endl;
        }
            else cout<<"No"<<endl;
    }

}
