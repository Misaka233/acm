#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double w,H,x,xe,ye,u,h;
        cin>>w>>H>>x>>xe>>ye>>u;
        double xx=w-tan(asin(sin(atan((xe-w)/(ye-H)))/u))*H;
        if(xx<x) cout<<"Impossible"<<endl;
        else
        {

            double th=asin(sin(atan((xe-w)/(ye-H)))/u);
            double th1=atan((xe-w)/(ye-H));//w-tanth1(H-h)-htanth=x;
            double h=(x-w+H*tan(th1))/(tan(th1)-tan(th));
            printf("%.4f\n",h);
        }
    }
    return 0;
}
