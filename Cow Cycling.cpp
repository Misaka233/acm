#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=100000000;
int N,E,D;
int dp[21][110][110];
int main()
{
    scanf("%d%d%d",&N,&E,&D);
    for(int i=0;i<=N;i++)
        for(int j=0;j<=D;j++)
            for(int k=0;k<=E;k++)
            {
                dp[i][j][k]=INF;
            }
    dp[1][0][0]=0;
    for(int i=1;i<=N;i++)
        for(int j=0;j<D;j++)
            for(int k=0;k<=E;k++)
                if(dp[i][j][k]!=INF)
                {
                    for(int s=0;s+j<=D&&s*s+k<=E;s++)
                        dp[i][j+s][k+s*s]=min(dp[i][j+s][k+s*s],dp[i][j][k]+1);
                    // 这里还有一个重要的转移! 当前奶牛退出比赛轮到下一头奶牛领跑。
                    // 注意能量变化，下头奶牛已经跑了j圈，初始能量消耗也应该为j
                     dp[i+1][j][j]=min(dp[i+1][j][j],dp[i][j][k]);
                }

    int ans=INF;
    for(int i=0;i<=E;i++)
    {
        ans=min(ans,dp[N][D][i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*dp[i][j][k]表示前i-1头奶牛都已耗尽能量或者中途离场，
现在第i头奶牛已经跑了j圈且已经消耗了k的能量，假设，当前奶
牛继续以l圈/分钟的速度跑一分钟，则状态
dp[i][j+l][k+l*l] = dp[i][j][k] + 1，（j+l <= D，j+l*l <= E），
当然，状态是否转移，要判断转移后所消耗时间是否更小。其次，每头奶
牛可以在任何时候随时退场，轮到下一头奶牛领跑，
所以还有一个特别点的转移方式，dp[i+1][j][j] = dp[i][j][k]，
主要理解的是能量的变化，因为第i+1头奶牛刚刚领跑，之前一共跟跑了j圈，
所以已经消耗的能量是j
*/
