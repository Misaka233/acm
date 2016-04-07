#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int cost[505][505];
bool used[505];
int mincost[505];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   int V,e;
        int res=0;
        cin>>V>>e;
        for(int i=0;i<V;i++)
        {
            mincost[i]=99999999;
        }
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cost[i][j]=999999999;
            }
        }
        memset(used,false,sizeof(used));


        while(e--)
        {
            int v,u,k;
            cin>>v>>u>>k;
            cost[v][u]=cost[u][v]=k;
        }
       mincost[0]=0;
       while(true)
       {
           int v=-1;
           for(int u=0;u<V;u++)
           {
               if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
           }
           if(v==-1) break;
           used[v]=true;
           res+=mincost[v];
           for(int u=0;u<V;u++)
           {
               mincost[u]=min(mincost[u],cost[v][u]);
           }
       }
       cout<<res<<endl;
    }
    return 0;
}
