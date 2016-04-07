#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int d[20];
int dp[20][60000];
int a[20];
int A,B;
int dfs(int c,int l)//c is weishu,l is <=l
{
    if(l<0) return 0;
    if(l>=0&&c==0) return 1;
    if(dp[c][l]>=0) return dp[c][l];
    dp[c][l]=0;
    for(int i=0;i<10;i++) dp[c][l]+=dfs(c-1,l-d[c-1]*i);
    return dp[c][l];
}
int f(int n,int sum)
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
            for(int j=0;j<a[i];j++)  ans+=dfs(i,sum-k-d[i]*j);
        }
        else{
            for(int j=0;j<=a[i];j++)  ans+=dfs(i,sum-k-j);
        }
        k+=a[i]*d[i];
    }
    return ans;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<9;i++)
        {
            d[i]=1<<i;
        }
       memset(dp,-1,sizeof(dp));
    for(int cas=1;cas<=t;cas++)
    {

        scanf("%d%d",&A,&B);

        int aa=0,ii=0;
        while(A)
        {
            aa+=(A%10)*d[ii];
            A/=10;
            ii++;
        }
         printf("Case #%d: %d\n",cas,f(B,aa));
    }

    return 0;

}
