#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
#include<assert.h>
using namespace std;
typedef long long LL;

const int maxn=20010;

int baba[maxn],num[maxn],pp[maxn],n,m,qq;
struct E
{
    int u,v,w;
    bool operator < (const E& x) const
    {
        return w<x.w;
    }
}e[maxn*5];
struct Q
{
    int v,id;
    bool operator < (const Q& a) const
    {
        return v<a.v;
    }
}q[maxn];
int find(int x)
{
    return baba[x]==x?x:baba[x]=find(baba[x]);
}
void Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x>y) swap(x,y);
    baba[y]=x;
    num[x]+=num[y];
}

void init()
{
    for(int i=0;i<=n;i++)
    {
        baba[i]=i;
        num[i]=1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&qq);
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e+m);
        int co=0;
        for(int i=0;i<qq;i++)
        {
            q[i].id=i;
            scanf("%d",&q[i].v);

        }
        sort(q,q+qq);

        int ans=0;
        for(int i=0;i<qq;i++)
        {
            while(co<m&&e[co].w<=q[i].v)
            {
                int u=find(e[co].u);
                int v=find(e[co].v);
                co++;
                if(u==v) continue;
                ans+=(num[v]+num[u])*(num[v]+num[u]-1)-(num[v])*(num[v]-1)-(num[u])*(num[u]-1);
                //cout<<ans<<" ";
                Union(u,v);
            }
            //cout<<ans<<" ";
            pp[q[i].id]=ans;
        }
        for(int i=0;i<qq;i++)
        {
            printf("%d\n",pp[i]);
        }
    }
    return 0;
}
