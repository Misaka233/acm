#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int MAX_N=55;
const int MAX_M=10005;
double dp[MAX_M][MAX_N];
vector <int> g[MAX_N];
int n,m,d,v,u;
double solve(int x)
{
    double ans=0;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<=d;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(x==j) continue;
            double p=1.0/(g[j].size());
            for(int k=0;k<g[j].size();k++)
            {
                dp[i+1][g[j][k]]+=dp[i][j]*p;
            }
        }
        ans+=dp[i+1][x];
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&d);
        for(int i=0;i<=n;i++)
            g[i].clear();
        while(m--)
        {
            scanf("%d%d",&v,&u);
            g[v].push_back(u);
            g[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
            g[0].push_back(i);
        for(int i=1;i<=n;i++)
            printf("%.10lf\n",1.0-solve(i));
    }
    return 0;
}
