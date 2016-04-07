#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=120;
const int INF=0x3f3f3f;
int cost[maxn][maxn];
bool vis[maxn];
int lowc[maxn];
int Prim(int cost[][maxn],int n)//点是0~n-1
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;i++)lowc[i]=cost[0][i];
    for(int i=1;i<n;i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;j++)
        if(!vis[j]&&minc>lowc[j])
        {
            minc=lowc[j];
            p=j;
        }
        if(minc==INF)return -1;//原图不连通
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
    }
    return ans;
}
int main()
{
    int n,u,v,c,f;
    while(~scanf("%d",&n)&&n!=0)
    {
        for(int i=0;i<n*(n-1)/2;i++)
        {
            scanf("%d%d%d%d",&u,&v,&c,&f);
            if(f==1)
            {
                cost[u-1][v-1]=cost[v-1][u-1]=0;
            }
            else
            {
                cost[u-1][v-1]=cost[v-1][u-1]=c;
            }
        }
        cout<<Prim(cost,n)<<endl;
    }
    return 0;
}
