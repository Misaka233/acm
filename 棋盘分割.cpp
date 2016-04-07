#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include <iomanip>
using namespace std;
int data[9][9],sum[9][9];
double dp[14][9][9][9][9];
double cal(int x1,int y1,int x2,int y2)
{
    double ans=(double)(sum[x2][y2]+sum[x1-1][y1-1]-sum[x2][y1-1]-sum[x1-1][y2]);
    return ans*ans;
}
int main()
{
    int n,total=0;
    scanf("%d",&n);
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            scanf("%d",&data[i][j]);

            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + data[i][j];
            total+=data[i][j];
        }
    }
    for(int x1=1;x1<=8;x1++)
        for(int y1=1;y1<=8;y1++)
            for(int x2=x1;x2<=8;x2++)
                for(int y2=y1;y2<=8;y2++)
                    dp[0][x1][y1][x2][y2]=cal(x1,y1,x2,y2);
    for(int k=1;k<n;k++)
        for(int x1=1;x1<=8;x1++)
            for(int y1=1;y1<=8;y1++)
                for(int x2=x1;x2<=8;x2++)
                    for(int y2=y1;y2<=8;y2++)
                    {
                        int t;
                        dp[k][x1][y1][x2][y2] = (double)(1<<30);
                        for(t=x1; t<x2; ++t)
                        {
                            dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2], dp[0][x1][y1][t][y2]+dp[k-1][t+1][y1][x2][y2]);
                            dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2], dp[k-1][x1][y1][t][y2]+dp[0][t+1][y1][x2][y2]);
                        }

                        for(t=y1; t<y2; ++t)
                        {
                            dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2], dp[0][x1][y1][x2][t]+dp[k-1][x1][t+1][x2][y2]);
                            dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2], dp[k-1][x1][y1][x2][t]+dp[0][x1][t+1][x2][y2]);
                        }
                    }
    double ans = dp[n-1][1][1][8][8]*1.0/n - ((double)total*1.0/n)*((double)total*1.0/n);
    printf("%.3f\n",sqrt(ans));
    //cout<<setprecision(3)<<fixed<<sqrt(ans)<<endl;
    return 0;
}
