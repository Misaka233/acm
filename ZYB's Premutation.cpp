#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const int maxn=50010;
int a[maxn];
int dp[maxn];
int ans[maxn];
bool flag[maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
         {
             scanf("%d",&a[i]);
             flag[i]=true;
         }
         dp[1]=0;
         for(int i=2;i<=n;i++)
         {
             dp[i]=a[i]-a[i-1];
         }
         int co=n;
        for(int i=n;i>0;i--)
        {
            while(flag[co]==false)
            {
                co--;
            }
            int aa=co;
            for(int j=1;j<=dp[i];j++)
            {
                aa--;
                while(flag[aa]==false)
                {
                    aa--;
                }
            }
            ans[i]=aa;
            flag[aa]=false;
        }
        for(int i=1;i<n;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}
