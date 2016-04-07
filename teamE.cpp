#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
int n,d;

int x[1111],y[1111];
int dis(int i,int j)
{
    return ceil(sqrt(0.0+(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
}
char ans[1111];
int top;
bool vis[1111],use[1111];
int ev[111111],nxt[111111],head[1111],e;
void add(int u,int v)
{
    ev[e]=v,nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int p)
{
    vis[u]=1;
    for(int i=head[u];~i;i=nxt[i])
    {
        int v=ev[i];
        if(vis[v]) continue;
        dfs(v,u);
    }
}
int idx;
bool solve()
{
    memset(vis,0,sizeof(vis));
    dfs(0,0);
    for(int i=1;i<n;i++) if(!vis[i]) return 0;
    for(int i=n-1;i;i--)
    {
        use[i]=0;
        memset(head,-1,sizeof(head));e=0;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        {
            if(use[i]&&use[j]&&dis(i,j)<=d) add(i,j),add(j,i);
            if(!use[i]&&!use[j]) continue;
            if(!use[i]||!use[j]) if(dis(i,j)*2<=d) add(i,j),add(j,i);
        }
        memset(vis,0,sizeof(vis));
        dfs(0,0);int need=0;
        for(int j=0;j<n;j++) if(!vis[j]) need=1;
        use[i]=need;
    }

    for(int i=n-1;~i;i--) ans[top++]=use[i]+48;
    ans[top]=0;
    idx=0;
    while(ans[idx]==48) idx++;
    return 1;
}
int main()
{
    while(~scanf("%d%d",&n,&d))
    {
        e=top=0;
        memset(use,1,sizeof(use));
        memset(head,-1,sizeof(head));
        use[0]=1;
        for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(dis(i,j)<=d) add(i,j),add(j,i);
        if(solve()) puts(ans+idx);
        else puts("-1");

    }
    return 0;
}
