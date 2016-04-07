#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int digit[11];
int dp[11][700*9];
int a[11];

int dfs(int cnt,int les)
{
    if(les<0) return 0;
    if(les>=0 && cnt==0) return 1;
    if(dp[cnt][les]>=0) return dp[cnt][les];
    dp[cnt][les]=0;
    for(int i=0;i<10;i++) dp[cnt][les]+=dfs(cnt-1,les-digit[cnt-1]*i);
    return dp[cnt][les];
}

int calc(int n,int sum)
{
    int cnt=0,tmp=n;
    if(n==0) a[cnt++]=0;
    while(tmp)
    {
        a[cnt]=tmp%10;
        tmp/=10;
        cnt++;
    }
    int ans=0;
    int k=0;
    for(int i=cnt-1;i>=0;i--)
    {
        if(i!=0){
            for(int j=0;j<a[i];j++)  ans+=dfs(i,sum-k-digit[i]*j);
        }
        else{
            for(int j=0;j<=a[i];j++)  ans+=dfs(i,sum-k-j);
        }
        k+=a[i]*digit[i];
    }
    return ans;
}

int main()
{
    for(int i=0;i<=9;i++) digit[i]=(1<<i);
    int cs;
    scanf("%d",&cs);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=cs;i++)
    {
        int A,B,sum=0,p=0;
        scanf("%d%d",&B,&A);
        while(B)
        {
            sum+=digit[p]*(B%10);
            B/=10;p++;
        }
        printf("Case #%d: %d\n",i,calc(A,sum));
    }
    return 0;
}











int main()
{
    for(int i=0;i<=9;i++) digit[i]=(1<<i);
    int cs;
    scanf("%d",&cs);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=cs;i++)
    {
        int A,B,sum=0,p=0;
        scanf("%d%d",&B,&A);
        while(B)
        {
            sum+=digit[p]*(B%10);
            B/=10;p++;
        }
        printf("Case #%d: %d\n",i,calc(A,sum));
    }
    return 0;
