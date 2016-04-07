#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int dp[100000];
int a[100000];
int b[100000];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));

        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<=n;i++)
            dp[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<=k) {b[i]++;dp[i]=1}
        }
        int co=a[1];
        for(int i=2;i<=n;i++)
        {
            if(b[i]!=0)
            {
                co+=a[i];
                if(co<=k) dp[i]=dp[i]+dp[i-1];
                else {
                    dp[i]=1;
                    co=a[i];
                }
            }

        }
    }
}
