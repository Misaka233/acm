//iÊÇÄ¿±ê´®£¬
//dp[i][x][y]=min(dp[j][x+(i-j)][y+(i-j)]+i-j,dp[j][x+(i-j)][y]+i-j,dp[j][x][y]+i-j);
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>

using namespace std;
int times[12][12];
int f[1005][12][12];
int n,m;
char s[1005];
char t[1005];
int a[1005];
int b[1005];
int main()
{

    for (int i=0;i<10;++i){
        int j=1;
        while ((i+j)%10!=i) {
              times[i][(i+j)%10]=j;
              j++;
        }
    }
    while (scanf("%s%s",s,t)!=EOF)
    {
          n=strlen(s);
          for (int i=0;i<=n;++i)
              for (int j=0;j<=10;++j)
              for (int k=0;k<=10;++k) f[i][j][k]=n*10;

          for (int i=0;i<n;++i)
          {
              a[i+1]=s[i]-'0';
              b[i+1]=t[i]-'0';
          }
          f[0][a[1]][a[2]]=0;
          for (int i=0;i<n;++i)
          for (int j=0;j<10;++j)
          for (int k=0;k<10;++k)
          if (f[i][j][k]<10*n)
          {
              int t=times[j][b[i+1]];
              for (int l=0;l<=t;++l)
                  for(int p=0;p<=l;++p){
                  f[i+1][(k+l)%10][(a[i+3]+p)%10]=
                  min(f[i+1][(k+l)%10][(a[i+3]+p)%10],f[i][j][k]+t);
              }
              for (int l=0;l<=10-t;++l)
                  for(int p=0;p<=l;++p){
                  f[i+1][(k-l+10)%10][(a[i+3]-p+10)%10]=
                  min(f[i+1][(k-l+10)%10][(a[i+3]-p+10)%10],f[i][j][k]+10-t);
              }

          }
            int ans=99999999999;
            for (int i=0;i<10;++i)
             for (int j=0;j<10;++j)
              ans=min(ans,f[n][i][j]);
          cout << ans << endl;
    }
    return 0;
}



