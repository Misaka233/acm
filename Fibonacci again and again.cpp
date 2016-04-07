#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int N=1010;
int f[N],sg[N],hash[N];
void fib()
{
    f[0]=f[1]=1;
    for(int i=2;i<=16;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
}
void getSG(int n)
{

    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(hash,0,sizeof(hash));
        for(j=1;f[j]<=i;j++)
            hash[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)    //求mes{}中未出现的最小的非负整数
        {
            if(hash[j]==0)
            {
                sg[i]=j;
                break;
            }
        }
    }
}
int main()
{
    int m,n,p;
    fib();
    getSG(1000);

    while(scanf("%d%d%d",&m,&n,&p),m+n+p)
    {
        if(sg[m]^sg[n]^sg[p])
            cout<<"Fibo"<<endl;
        else
            cout<<"Nacci"<<endl;
    }
    return 0;
}
