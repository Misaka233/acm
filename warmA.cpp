#include<iostream>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,n;
    double x[110],y[110];
    x[0]=0;y[0]=0;
    x[1]=1;y[1]=0;
    x[2]=0.5;y[2]=sqrt(1-0.25);
    x[3]=0.5;y[3]=y[2]-1;
    for(int i=4;i<110;i++)
    {
        x[i]=1-i*0.001;
        y[i]=sqrt(1-x[i]*x[i]);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=3)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            for(int i=0;i<n;i++)
            {
                printf("%.6lf %.6lf\n",x[i],y[i]);
            }
        }
    }
    return 0;
}
