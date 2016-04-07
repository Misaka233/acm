#include<string.h>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
const int M =40100;
const double inf = 1e20;
int min(int a,int b){return a<b?a:b;}
int n,k,tdfn,tot;
int dp[20][2*M],vis[M];
int B[2*M],LOG[2*M],used[M],F[2*M],pos[M];
vector<pair<int,int> > edge[2*M];
void rmq_init(int n,int num[])
{
    int i,j;
    for(j=1;j<=n;j++)
        dp[0][j]=num[j];
    for(j=1;j<=LOG[n];j++)
    {
        int limit=n+1-(1<<j);
        for(i=1;i<=limit;i++)
        {
            int x=i+(1<<j>>1);
            dp[j][i]=min(dp[j-1][x],dp[j-1][i]);
        }
    }
}
int rmq(int l,int r,int num[])
{
    int m=LOG[r-l+1];
    return min(dp[m][l],dp[m][r-(1<<m)+1]);
}
int sum[M];
void dfs(int s)
{
    int i,t;
    used[s]=1;
    int tmp=++tdfn;
    B[++tot]=tmp;F[tmp]=s;
    pos[s]=tot;
    for(i=0;i<edge[s].size();i++)
    {
        t=edge[s][i].first;
        if(used[t])  continue;
        sum[t]=sum[s]+edge[s][i].second;
        dfs(t);
        B[++tot]=tmp;//backtrack
    }
}
int lca(int a,int b)
{
    if(pos[a]>pos[b]) swap(a,b);
    int ans=rmq(pos[a],pos[b],B);
    return F[ans];
}
int main()
{
    int i,n,m,a,b,w;
    LOG[0]=-1;
    for(i=1;i<2*M;i++)  LOG[i]=LOG[i>>1]+1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++) edge[i].clear();
        char str[5];
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%s",&a,&b,&w,str);
            edge[a].push_back(make_pair(b,w));
            edge[b].push_back(make_pair(a,w));
        }
        sum[1]=0;
        tdfn=0;
        tot=0;
        memset(used,0,sizeof(used));
        dfs(1);
        rmq_init(tot,B);
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",sum[a]+sum[b]-2*sum[lca(a,b)]);
        }
    }
    return 0;
}
