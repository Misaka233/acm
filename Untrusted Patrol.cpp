#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N=100002;
bool vis[N];
bool jcgq[N];
int cgq[N];
vector<int>e[N];
int n,m,k,cgqco;
void init()
{
    int v,u;
    memset(vis,false,sizeof(vis));
    memset(jcgq,false,sizeof(jcgq));
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
        scanf("%d",&v);
    for(int i=0;i<=n;i++)
        e[i].clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    scanf("%d",&cgqco);
    for(int i=0;i<cgqco;i++)
    {
        scanf("%d",&cgq[i]);
        jcgq[cgq[i]]=true;
    }
    return ;
}
void bfs(int x)
{
    queue <int> q;
    int a;
    q.push(x);
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        for (int i=0; i<(int)e[a].size(); ++i)
        {
            if (!vis[e[a][i]])
            {
                vis[e[a][i]] = true;


                if (jcgq[e[a][i]]) continue;
                q.push(e[a][i]);
            }
        }
    }
    return;
}
void solve()
{
    if (cgqco != k)
    {
        printf("No\n");
        return;
    }
    vis[cgq[0]]=true;
    for (int i=0; i<cgqco; ++i)
    {
        if (!vis[cgq[i]])
        {
            printf("No\n");
            return;
        }
        bfs(cgq[i]);
    }
    for (int i=1; i<=n; ++i)
    {

     if (!vis[i])
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        solve();
    }
    return 0;
}
