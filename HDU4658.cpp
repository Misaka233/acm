#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MOD=1e9+7;
int dp[100010];
void init()
{
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i = 1;i <= 100000;i++)
    {
        for(int j = 1, r = 1; i - (3 * j * j - j) / 2 >= 0; j++, r *= -1)
        {
            dp[i] += dp[i -(3 * j * j - j) / 2] * r;
            dp[i] %= MOD;
            dp[i] = (dp[i]+MOD)%MOD;
            if( i - (3 * j * j + j) / 2 >= 0 )
            {
                dp[i] += dp[i - (3 * j * j + j) / 2] * r;
                dp[i] %= MOD;
                dp[i] = (dp[i]+MOD)%MOD;
            }
        }
    }
}
int solve(int n,int k)
{
    int ans = dp[n];
    for(int j = 1, r = -1; n - k*(3 * j * j - j) / 2 >= 0; j++, r *= -1)
    {
        ans += dp[n -k*(3 * j * j - j) / 2] * r;
        ans %= MOD;
        ans = (ans+MOD)%MOD;
        if( n - k*(3 * j * j + j) / 2 >= 0 )
        {
        ans += dp[n - k*(3 * j * j + j) / 2] * r;
        ans %= MOD;
        ans = (ans+MOD)%MOD;
        }
    }
return ans;
}
int main()
{
    init();
    int T;
    int n,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",solve(n,k));
    }
}

