#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1000+10;
const int MAXM=100000+10;
struct node
{
    int v,c;
    node(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator<(const node &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>e[MAXM];
vector<Edge>e2[MAXM];
void addedge(int u,int v,int c)
{
    e[u].push_back(Edge(v,c));
}
void addedge2(int u,int v,int c)
{
    e2[v].push_back(Edge(u,c));
}
bool vis[MAXN];
bool vis2[MAXN];
int dist[MAXM];
int dist2[MAXM];
void Dijkstra(int n,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<node>que;
    while(!que.empty()) que.pop();
    dist[start]=0;
    que.push(node(start,0));
    node tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[tmp.v][i].v;
            int cost=e[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(node(v,dist[v]));
            }
        }
    }
}
void Dijkstra2(int n,int start)//点的编号从1开始
{
    memset(vis2,false,sizeof(vis2));
    for(int i=1;i<=n;i++)dist2[i]=INF;
    priority_queue<node>qu;
    while(!qu.empty()) qu.pop();
    dist2[start]=0;
    qu.push(node(start,0));
    node tmp;
    while(!qu.empty())
    {
        tmp=qu.top();
        qu.pop();
        int u=tmp.v;
        if(vis2[u])continue;
        vis2[u]=true;
        for(int i=0;i<e2[u].size();i++)
        {
            int v=e2[tmp.v][i].v;
            int cost=e2[u][i].cost;
            if(!vis2[v]&&dist2[v]>dist2[u]+cost)
            {
                dist2[v]=dist2[u]+cost;
                qu.push(node(v,dist2[v]));
            }
        }
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        addedge(u,v,c);
        addedge2(u,v,c);
    }
    Dijkstra(n,k);
    Dijkstra2(n,k);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i==k) continue;
        ans=max(ans,dist2[i]+dist[i]);
    }
    cout<<ans<<endl;
    return 0;
}
