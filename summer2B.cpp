
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 105
using namespace std;

int n,m,ans;
bool mp[maxn][maxn];
int vis[maxn][maxn];
struct Node
{
    int x,y;
} pp[21];

bool cmp(Node xx,Node yy)
{
    if(xx.y!=yy.y) return xx.y<yy.y;
    if(xx.x!=yy.x) return xx.x<yy.x;
}
void dfs(int pos,int val)
{
    if(ans<val) ans=val;
    if(pos>n||val+n-pos+1<=ans) return ;
    int i,j,x,y,tx,ty,edge;
    x=pp[pos].x;
    y=pp[pos].y;
    if(vis[x][y]<=0) dfs(pos+1,val);
    else
    {
        for(i=pos+1; i<=n; i++)
        {
            tx=pp[i].x;
            ty=pp[i].y;
            if(ty>y) break ;
            edge=tx-x;
            if(edge==0) continue ;
            if(mp[x][y+edge]&&mp[tx][y+edge])
            {
                if(vis[x][y]<=0||vis[tx][ty]<=0||vis[x][y+edge]<=0||vis[tx][y+edge]<=0)
                    continue ;
                vis[x][y]--,vis[tx][ty]--;
                vis[x][y+edge]--,vis[tx][y+edge]--;
                dfs(pos+1,val+4);
                vis[x][y]++,vis[tx][ty]++;
                vis[x][y+edge]++,vis[tx][y+edge]++;
            }
        }
        dfs(pos+1,val);
    }
}
int main()
{
    int i,j;
    while(scanf("%d",&n))
    {
        if(n==-1) break ;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            scanf("%d%d",&pp[i].x,&pp[i].y);
            mp[pp[i].x][pp[i].y]=1;
            vis[pp[i].x][pp[i].y]++;
        }
        sort(pp+1,pp+n+1,cmp);
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
