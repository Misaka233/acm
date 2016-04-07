#include <bits/stdc++.h>
using namespace std;
double dp[1010][1<<10];
bool vis[1010][1<<10];
double p[10][1010];
int n,m;
double dfs(int id,int s){
	if(s == (1<<n)-1)s = 0;
	if(vis[id][s])return dp[id][s];
	vis[id][s] = true;
	dp[id][s] = 0;
	if(id == m)return dp[id][s];
	for(int i = 0;i < n;i++){
		if(s&(1<<i))continue;
		dp[id][s] = max(dp[id][s],(1-p[i][id])*dfs(id+1,s|(1<<i))+p[i][id]*(dfs(id+1,s|(1<<i))+1));
	}
	return dp[id][s];
}
int main()
{

    int t;
	int iCase = 0;
	scanf("%d",&t);
	for(int iCase=1;iCase<=t;iCase++)
    {

		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				scanf("%lf",&p[i][j]);
		memset(vis,false,sizeof(vis));
        printf("Case #%d: %.5lf\n",iCase,dfs(0,0));
	}
    return 0;
}

