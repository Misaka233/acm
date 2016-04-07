#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct misaka
{
    int t,v,s;
}a[110];
int dp[110][110];
bool cmp(misaka a,misaka b)
{
    return a.t<b.t;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,ttt;
        scanf("%d%d%d",&n,&k,&ttt);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].t);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].s);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=0;i<110;i++)
        {
            for(int j=0;j<110;j++)
            {
                dp[i][j]=-2333333;
            }
        }
        dp[0][0]=0;
        a[0].s=0;a[0].t=0;a[0].v=0;
        int ans=0;
        for(int i=1;i<=n&&a[i].t<=ttt;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int tem=a[i].t-a[j].t;
                for(int kk=max(0,a[i].s-tem);kk<=min(k,a[i].s+tem);kk++)
                {
                    dp[i][a[i].s]=max(dp[i][a[i].s],dp[j][kk]+a[i].v);
                    //cout<<dp[i][a[i].s]<<" ";
                }
                ans=max(ans,dp[i][a[i].s]);
                //cout<<ans<<" ";
            }
        }
        cout<<ans<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
