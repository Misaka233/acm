#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,root;
long long dp[maxn];
int a[maxn];
vector<int>g[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int u, int uu)
{
    vector<long long>s;
    dp[u] =1;
	for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(v==uu||!a[v]) continue;
		a[v]--;
		dfs(v, u);
        if(dp[v])
        {
            s.push_back(dp[v]);
        }
    }
	sort(s.begin(), s.end(),cmp);
	for(int i = 0; a[u] && i < s.size(); i++)
    {
        a[u]--;
        dp[u] += s[i] +1;
    }
    for(int i = 0; a[u] && i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(v == uu || a[v] == 0) continue;
        dp[u]+=2LL*min(a[u], a[v]);
        a[u]-=min(a[u], a[v]);
    }
}
int main()
{
    int u, v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]), g[i].clear();
    }
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d",&root);
    dfs(root, root);
    printf("%I64d",dp[root]-1);
    return 0;
}
