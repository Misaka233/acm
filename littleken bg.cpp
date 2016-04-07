#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[6000];
int a[40];
int m,n;
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=m;j>=a[i];j--)
            {
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
