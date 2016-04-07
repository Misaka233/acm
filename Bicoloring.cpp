#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
const int maxn=210;
int map[maxn][maxn],vis[maxn];
bool col[maxn];
int dfs(int x)
{
    for(int i=0;i<n;i++)
    {
        if(map[x][i])
        {
            if(!vis[i])
            {
                vis[i]=1;
                col[i]=!col[x];
                dfs(i);
            }
            else if(col[i]==col[x])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(col,-1,sizeof(col));
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        int u,v;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            map[u][v]=1;
            map[v][u]=1;
        }
        col[0]=1;
        vis[0]=1;
        if(dfs(0))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
