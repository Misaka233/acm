#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[15][100010];
int main()
{
    int n,x,t;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(dp,0,sizeof(dp));
        int time=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            dp[x][t]++;
            time=max(time,t);
        }
        for(int j=time-1;j>=0;j--)
        {
            dp[0][j]+=max(dp[0][j+1],dp[1][j+1]);
            dp[10][j]+=max(dp[10][j+1],dp[9][j+1]);
            for(int i=1;i<10;i++)
            {
                dp[i][j]+=max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1]));
            }
        }
        printf("%d\n",dp[5][0]);
    }
    return 0;
}
