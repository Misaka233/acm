#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int maxn=360;
int a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++)
        dp[i][0]=dp[i-1][0]+a[i][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[n-1][i]);
    printf("%d\n",ans);
    return 0;
}
