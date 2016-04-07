#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000+10;
const int MAXM=20000+10;
const int INF=0x3f3f3f3f;
int cost[MAXN][MAXN];

bool vis[MAXN];
int lowc[MAXN];
int Prim(int cost[][MAXN],int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;i++) lowc[i]=cost[0][i];
    for(int i=1;i<n;i++)
    {
        int minc=0;
        int p=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&minc<lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==0) return -1;
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&lowc[j]<cost[p][j])
            {
                lowc[j]=cost[p][j];
            }
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        cost[v-1][u-1]=cost[u-1][v-1]=max(cost[u-1][v-1],c);
    }
    cout<<Prim(cost,n)<<endl;;
    return 0;
}
