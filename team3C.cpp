#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>

using namespace std;
int main()
{
    int t;
    double x,y,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&x,&y,&p,&q);
        double t=(1-q)*x+q*p*(x+y);
        double w=q*y+(1-q)*p*(x+y);
        if(t>=w)
        {
            printf("tiger %.4lf\n",t);
        }
        else {
            printf("wolf %.4lf\n",w);
        }
    }
}
