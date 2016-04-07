#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1007;
int dp[maxn][maxn];
int a[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=n;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        int ans=dp[0][n-1];
        for(int i=0;i<n-1;i++)
            ans=max(ans,dp[0][i]+dp[i+1][n-1]);
        cout<<ans<<endl;

    }
    return 0;
}
