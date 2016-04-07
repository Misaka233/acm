#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=1010;
int head[maxn];
int p;
int n,m;
struct node{
    int v,w,cut,next;
}edge[maxn*maxn*2];
int dfn[maxn],low[maxn],dex;



void tarjan(int u,int pre)
{
    dfn[u]=low[u]=++dex;
    int prenum=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        int w=edge[i].w;
        if(pre==v&&prenum==0)
        {
            prenum++;
            continue;
        }
        if(!dfn[v])
        {
            tarjan(v,u);
            if(low[u]>low[v]) low[u]=low[v];
            if(low[v]>dfn[u])
            {
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
        }
        else if(low[u]>dfn[v])
        {
            low[u]=dfn[v];
        }
    }
}

int main()
{
    while(scanf("%d %d",&n,&m))
    {
        p=0;
        if(n==0&&m==0) break;
        memset(head,-1,sizeof(head));
        p=0;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edge[p].v=v;
            edge[p].w=w;
            edge[p].cut=0;
            edge[p].next=head[u];
            head[u]=p++;
            edge[p].v=u;
            edge[p].w=w;
            edge[p].cut=0;
            edge[p].next=head[v];
            head[v]=p++;
        }
        memset(dfn,0,sizeof(dfn));
    dex=0;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            tarjan(i,i);
            num++;
        }
    }
    if(num>1)
    {
        printf("0\n");
    }
    else
    {
        int ans=0xfffff;
        for(int u=1;u<=n;u++)
        {
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                if(edge[i].cut)
                {
                    ans=min(ans,edge[i].w);
                }
            }
        }
        if(ans==0xfffff)ans=-1;
        if(ans==0)ans++;
        printf("%d\n",ans);
    }
    }

    return 0;
}
