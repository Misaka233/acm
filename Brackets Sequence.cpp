#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=123;
const int inf=0x3f3f3f3f;
int dp[maxn][maxn],pa[maxn][maxn];
char s[maxn];
int len;
void out(int first,int end)
{
    if(first>end)
        return ;
    else if(first==end)
    {
        if(s[first]=='('||s[end]==')')
            printf("()");
        else printf("[]");
    }
    else if(pa[first][end]==-1)
    {
        printf("%c",s[first]);
        out(first+1,end-1);
        printf("%c",s[end]);
    }
    else
    {
        out(first,pa[first][end]);
        out(pa[first][end]+1,end);
    }

}
int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%s",s+1);
    len=strlen(s+1);
    //cout<<len<<endl;
    for(int i=1;i<=len;i++)
    {
        dp[i][i]=1;
    }
    for(int l=2;l<=len;l++)
    {
        for(int i=1;i<=len-l+1;i++)
        {
            int j=i+l-1;
            if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')
            {
                dp[i][j]=dp[i+1][j-1];
                pa[i][j]=-1;
            }
            else dp[i][j]=inf;
            for(int k=i;k<=j-1;k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j];
                    pa[i][j]=k;
                }
            }
        }
    }
    out(1,len);
    printf("\n");
    return 0;
}
