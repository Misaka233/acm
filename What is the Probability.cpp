#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,an;
double p;
double ans,a1;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf%d",&n,&p,&an);
        if(p==0) ans=0;
        else
        {
            a1=p*(1-pow(1-p,1000*n))/(1-pow(1-p,n));
            //cout<<a1<<" ";
            ans=a1*pow(1-p,an-1);
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}
