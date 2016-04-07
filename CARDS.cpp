#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
const int maxn=1010;
int a[maxn],b[maxn],c[maxn];
int n,s;
int solve()
{
    int cn=0,i;
    while(1)
    {
        for(i=1;i<=n;i++)
        {
            b[i]=c[c[i]];
        }

        cn++;
        for(i=1;i<=n;i++)
        {if(a[i]!=b[i])
            break;
        }
        if(i>n)
            break;
        for(i=1;i<=n;i++)
            c[i]=b[i];
    }
    return cn;
}

int main()
{
    while(~scanf("%d%d",&n,&s))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
            c[i]=a[i];
        }
        int co=solve();
        s%=co;
        s=co-s;

        while(s--)
        {
            for(int i=1;i<=n;i++)
            {
                b[i]=a[a[i]];
            }
            for(int i=1;i<=n;i++)
            {
                a[i]=b[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d\n",b[i]);
        }
    }
    return 0;
}
