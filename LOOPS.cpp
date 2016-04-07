#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1010;
double a[3][maxn][maxn];//²»¶¯¡¢ÓÒ¡¢ÏÂ
double dp[maxn][maxn];
int main()
{

    int r,c;
    while(~scanf("%d%d",&r,&c))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                scanf("%lf %lf %lf",&a[0][i][j],&a[1][i][j],&a[2][i][j]);
            }
        }
        for(int i=r;i>=1;i--)
        {
            for(int j=c;j>=1;j--)
            {
                if(i==r&&j==c)
                    continue;
                if(a[0][i][j]==1)
                    continue;
                dp[i][j]=(dp[i][j+1]*a[1][i][j]+dp[i+1][j]*a[2][i][j]+2)/(1.0-a[0][i][j]);
            }
        }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}

