#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
cosnt int maxn =100000;
using namespace std;
int n,q,s;
struct misaka{
    int id;
    int to;
    int cost;
};
int a[maxn],b[maxn],v[maxn];
int type[maxn];
vector<misak>g[maxn];
int root;
int  vs[maxn*2];
int depth[maxn*2];
int id[maxn];
int es[2*maxn];
void dfs(int v,int p,int d,int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<g.size(),i++)
    {
        misaka &e=g[v][i];
        if(e.to!=p)
        {
            add(k,e.cost);
            es[e.id*2]=k;
            dfs(e.to,v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
            add(k,-e.cost);
            es[e.id*2+1]=k;
        }
    }
}
int stack_v[maxn+10];
int stack_i[maxn+10];
void init(int V)
{
    bit_n=(V-1)*2;
    int k=0;
    dfs(root,-1,0,k);
    rmq_init(depth,V*2-1);
}
int lca(int u,int v)
{
    return vs[query(min(id[u],id[v]),max(id[u],id[v])+1)];
}
void solve()
{
    root=n/2;
    for(int i=0;i<n-1;i++)
    {
        g[a[i]-1].push_back((e){i,b[i]-1,w[i]});
        g[b[i]-1].push_back((e){i,a[i]-1,w[i]});
    }
    init(n);
    int v=s-1;
    for(int i=0;i<q;i++)
    {
        if(type[i]==0)
        {
            int u=x[i]-1;
            int p=lca(v,u);
            cout<<sum(id[v])+sum(id[v])-2*sum(id[p])<<endl;
            v=u;
        }
        else
        {
            int k=x[i]-1;
            add(es[k*2],t[i]-w[k]);
            add(es[k*2+1],w[k]-t[i]);
            w[k]=t[i];
        }
    }
}
int main()
{

    return 0;
}



