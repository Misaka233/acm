#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=120;
struct misaka{
    int t1,t2,t3;
    int f1,f2;
}a[maxn];
int dp[maxn][maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n,m;
        cin>>n>>m;

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=999999999;
            }
        }
        for(int i=0;i<n;i++)
        {
            cin>>a[i].t1>>a[i].t2>>a[i].t3>>a[i].f1>>a[i].f2;
        }
        dp[0][m]=0;
       for(int i=0;i<n;i++)
			for(int j=0;j<=m;j++)
			{
				if(j>=a[i].f1)// fastest
				{
					dp[i+1][j-a[i].f1]=min(dp[i+1][j-a[i].f1],dp[i][j]+a[i].t1);
				}
				if(j+a[i].f2>m)//slowest
				{
					dp[i+1][m]=min(dp[i+1][m],dp[i][j]+a[i].t3);
				}
				else
				{
					dp[i+1][j+a[i].f2]=min(dp[i+1][j+a[i].f2],dp[i][j]+a[i].t3);
				}
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i].t2);//normal
			}
        int ans=1<<25;
        for(int i=0;i<=m;i++)
        {
            if(dp[n][i]<ans)
                ans=dp[n][i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
