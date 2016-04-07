#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b)//最大公约数
{
    return b>0?gcd(b,a%b):a;
}
int main()
{
    int n;
    long long f[50],u[50],d[50];
    f[1]=1;
    u[1]=d[1]=0;
    for(int i=2;i<=33;i++)
    {
        long long t1=0,t2=1;
        for(int j=1;j<=i;j++)
        {
            t1=t1*j+t2*i;
            t2*=j;
            long long t=gcd(t1,t2);
            t1/=t;
            t2/=t;
        }
        f[i]=t1/t2;
        u[i]=t1%t2;
        d[i]=t2;
    }
    while(~scanf("%d",&n))
    {
        if(u[n]!=0)
        {
            for(long long i=f[n];i>0;i/=10)
                cout<<" ";
            cout<<" ";
            cout<<u[n]<<endl;
            cout<<f[n]<<" ";
            for(long long i=d[n];i>0;i/=10)
                cout<<"-";
            cout<<endl;
            for(long long i=f[n];i>0;i/=10)
                cout<<" ";
            cout<<" ";
            cout<<d[n]<<endl;

        }
        else
        {
            printf("%d\n",f[n]);
        }
    }
    return 0;
}
