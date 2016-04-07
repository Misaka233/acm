#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5005;
const int inf=1<<30;
int dp[1005][maxn];
int a[maxn];
int k,n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(0));
        scanf("%d%d",&k,&n);
        k+=8;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
       for(int i=1;i<=k;i++)
        {
            for(int j=i*2;j<=n;j++)
            {
                dp[i][j]=inf;
                if(j>2*i)
                dp[i][j]=dp[i][j-1];
                if(n-j>(k-i)*3)
                dp[i][j]=min(dp[i][j],dp[i-1][j-2]+(a[j-1]-a[j])*(a[j-1]-a[j]));
            }
        }
        printf("%d\n",dp[k][n]);
    }
    return  0;
}
