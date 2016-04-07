#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=100010;
int first[maxn];
int d[maxn],num[maxn];
int deep;
struct node
{
    int v;
    int next;
}edge[maxn*2];
void dfs(int u,int ba,int deepth)
{
    if(num[u]) deep=max(deep,deepth);
    d[deepth]+=num[u];
    for(int i=first[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==ba) continue;
        dfs(v,u,deepth+1);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,root;
        int co=0;
        memset(first,-1,sizeof(first));
        memset(d,0x3f,sizeof(d));
        scanf("%d%d",&n,&root);
        for(int i=1;i<n;i++)
        {
            int v,u;
            scanf("%d%d",&u,&v);
            edge[co].next = first[u];
            edge[co].v = v;
            first[u] = co++;
            edge[co].next = first[v];
            edge[co].v = u;
            first[v] = co++;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        long long ans=0;
        for(int i=first[root];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            deep=0;
            memset(d,0,sizeof(d));
            dfs(v,root,0);
            long long t1=0,t2=0;
            for(int i=0;i<=deep;i++)
            {
                t1+=d[i];
                if(d[i]==0&&t1+t2<=i)
                    t2++;
            }
            ans=max(t1+t2,ans);
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
