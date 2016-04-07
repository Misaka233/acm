//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
const double eps=1e-8;
const double PI=acos(-1);
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point (){}
    Point(double _x,double _y)
    {
        x=_x;y=_y;
    }
    Point operator - (const Point &b) const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^ (const Point &b) const
    {
        return x*b.y-y*b.x;
    }
    double operator * (const Point &b) const
    {
        return x*b.x+y*b.y;
    }
    //绕原点旋转B(弧度值);
    void transXY(double B)
    {
        double tx=x,ty=y;
        x=tx*cos(B)-ty*sin(B);
        y=tx*sin(B)+ty*cos(B);
    }
};
struct Line
{
    Line(){}
    Point s,e;
    Line(Point _s,Point _e)
    {
        s=_s;e=_e;
    }
};
//判断线段相交
bool inter(Line l1,Line l2)
{
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
double dist(Point a,Point b)
{
    return sqrt((a-b)*(a-b));
}
const int MAXN = 100010;
Line line[MAXN];
bool flag[MAXN];
int main()
{
    int n;
    double x1,y1,x2,y2;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            line[i]=Line(Point(x1,y1),Point(x2,y2));
            flag[i]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(inter(line[i],line[j]))
                {
                    flag[i]=false;
                    break;
                }
            }
        }
        cout<<"Top sticks: ";
        int co=1;
        for(int i=1;i<=n;i++)
        {
            if(flag[i]&&co)
            {
                printf("%d",i);
                co=0;
            }
            else if(flag[i])
            {
                printf(", %d",i);
            }
        }
        cout<<"."<<endl;
    }
    return 0;
}
