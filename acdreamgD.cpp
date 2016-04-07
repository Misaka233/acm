#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int N,M,K,u,v,k;
int dp[1005][12];
int map[1005][1005];
int used[1005];
int main()
{
    while(~scanf("%d %d %d",&N,&M,&K))
    {
        memset(used,false,sizeof(used));
        for(int i=0;i<1005;i++)
        {
            for(int j=0;j<12;j++)
                dp[i][j]=INF;
        }
        for(int i=0;i<1005;i++)
        {
            for(int j=0;j<1005;j++)
            {
                map[i][j]=INF;
            }
        }
        for(int i=1;i<=M;i++){
            cin>>u>>v>>k;
            map[u][v]=map[v][u]=min(map[v][u],k);
        }
            used[1]=true;
            dp[1][0]=0;


                int mmin=INF;
                for(int i=1;i<=N;i++)
                {
                    for(int j=0;j<=K;j++)
                    {
                        if(dp[i][j]>mmin) mmin=dp[i][j];
                    }
                }
                cout<<mmin<<endl;

    }
    return 0;
}
