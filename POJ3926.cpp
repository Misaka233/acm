#include<iostream>
#define oo 1000000000
#define MAXN 10015
using namespace std;
int n,m,L,i,j,k,p,x,h1,h2,line[MAXN],pop[115][MAXN],len[MAXN],dp[2][MAXN],ans;
char s[2000001];
int getint()
{
    int data=0,u=1;
    while (s[x]<'0' || s[x]>'9' ) x++;
    if (x && s[x-1]=='-')  u=-1;
    while (s[x]>='0' && s[x]<='9')
    {
          data=data*10+s[x]-'0';
          x++;
    }
    return data*u;
}
int main()
{
    while (gets(s))
    {
          x=0;
          n=getint(); m=getint(); L=getint();
          if (!n && !m && !L) break;
          for (i=1;i<=n+1;i++)
          {
                gets(s); x=0;
                pop[i][0]=0;
                for (j=1;j<=m;j++)
                {
                     pop[i][j]=getint();
                     pop[i][j]+=pop[i][j-1];
                }
          }
          p=1;  len[0]=0;
          memset(dp[p],0,sizeof(dp[p]));
          for (k=1;k<=n+1;k++)
          {
                p=1-p;
                gets(s); x=0;
                for (i=1;i<=m;i++)
                {
                      len[i]=getint();
                      len[i]+=len[i-1];
                }
                memset(dp[p],0,sizeof(dp[p]));
                h1=1; h2=0;
                for (i=0;i<=m;i++)
                {
                      while (h1<=h2 && len[i]-len[line[h1]]>L) h1++;
                      while (h1<=h2 && dp[1-p][line[h2]]+pop[k][i]-pop[k][line[h2]]<=dp[1-p][i]) h2--;
                      line[++h2]=i;
                      dp[p][i]=dp[1-p][line[h1]]+pop[k][i]-pop[k][line[h1]];
                }//  单调队列1 左往右
                h1=1; h2=0;
                for (i=m;i>=0;i--)
                {
                      while (h1<=h2 && len[line[h1]]-len[i]>L) h1++;
                      while (h1<=h2 && dp[1-p][line[h2]]+pop[k][line[h2]]-pop[k][i]<=dp[1-p][i]) h2--;
                      line[++h2]=i;
                      if (dp[p][i]<dp[1-p][line[h1]]+pop[k][line[h1]]-pop[k][i])
                          dp[p][i]=dp[1-p][line[h1]]+pop[k][line[h1]]-pop[k][i];
                }//  单调队列2 右往左
          }
          ans=0;
          for (i=0;i<=m;i++) ans=ans>dp[p][i]?ans:dp[p][i];
          printf("%d\n",ans);
    }
    return 0;
}

