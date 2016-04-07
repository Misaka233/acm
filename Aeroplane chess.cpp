#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
double a[100010];
int b[100010];
int x[1111],y[1111];
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m),(n||m))
    {
        memset(a,0,sizeof(a));
        memset(b,-1,sizeof(b));
        for(int i=1;i<=m;i++)
            {
                scanf("%d %d",&x[i],&y[i]);
                b[x[i]]=y[i];
            }
        for(int i=n-1;i>=0;i--)
        {
            if(b[i]==-1)
            {
                a[i]=(a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6])/6.0+1.0;
            }
            else
            {
                a[i]=a[b[i]];
            }
        }
        printf("%.4lf\n",a[0]);
    }
    return 0;
}
