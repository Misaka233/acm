//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=50005;
int N,M,V;
int A[maxn],B[maxn];
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;//∫Û–Ú±È¿˙À≥–Ú
bool used[maxn];
int cmp[maxn];//Õÿ∆À≈≈–Ú

void add(int f,int t)
{
    G[f].push_back(t);
    rG[t].push_back(f);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
    {
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++)
    {
        if(!used[v]) dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    cin>>N>>M;
    V=N;
    for(int i=0;i<M;i++)
    {
        cin>>A[i]>>B[i];
        add(A[i]-1,B[i]-1);
    }
    int n=scc();
    int u=0,num=0;
    for(int v=0;v<V;v++)
    {
        if(cmp[v]==n-1)
        {
            u=v;
            num++;
        }
    }
    memset(used,0,sizeof(used));
    rdfs(u,0);
    for(int v=0;v<V;v++)
    {
        if(!used[v])
        {
            num=0;
            break;
        }
    }
    cout<<num<<endl;
    return 0;
}
