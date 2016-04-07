#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[105][105];
int a[105];
int s[105];
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=999999999;
            }
        }
        for(int l=1;l<n;l++)
        {
            for(int i=1;i<=n-l;i++)
                {
                    int j=i+l;
                    for(int k=i;k<=j;k++)
                    {
                        dp[i][j]=min(dp[i][j],a[i]*(k-i)+(k-i+1)*(s[j]-s[k])+dp[i+1][k]+dp[k+1][j]);
                    }
            }
        }
       cout<<"Case #"<<cas<<": "<<dp[1][n]<<endl;
    }
}
