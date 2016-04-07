#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int INF=99999999;
int cost[1005][1005];
bool used[1005];
int mincost[1005];
int s[1005];
int k;
int main()
{
    int V;
    while(scanf("%d",&V)!=EOF)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cost[i][j]=INF;
            }
        }
        for(int i=0;i<V;i++)
        {
            mincost[i]=INF;
        }
        memset(used,false,sizeof(used));
        for(int i=1;i<V;i++)
        {
            cin>>k;
            cost[0][i]=cost[i][0]=k;
        }
        for(int i=1;i<V;i++)
        {
            for(int j=1;j<V;j++)
            {
                cin>>k;
                cost[i][j]=cost[j][i]=k;
                if(i==j) cost[i][j]=cost[j][i]=INF;
            }
        }
       mincost[0]=0;
       int res=0;
       while(true)
       {
           int v=-1;
           for(int u=0;u<V;u++){
                if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
           }
           if(v==-1) break;
           used[v]=true;
           res+=mincost[v];
           for(int u=0;u<V;u++){
                mincost[u]=min(mincost[u],cost[v][u]);
           }
       }
       cout<<res<<endl;
    }
    return 0;
}
