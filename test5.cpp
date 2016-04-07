#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define inf 99999999
#define maxn 10001

using namespace std;

int n,m;
vector<int>map[maxn];

void init()
{
	int i;
	for(i=1;i<=n;i++)
		map[i].clear();
}

int bfs()
{
	int i,now,count=0;
	bool used[maxn];
	int pre[maxn];
	memset(used,0,sizeof(used));
	memset(pre,0,sizeof(pre));
	queue<int>q;
	q.push(1);
	used[1]=true;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(i=0;i<map[now].size();i++)
			pre[map[now][i]]=now;
		for(i=1;i<=n;i++)
		{
			if(pre[i]!=now&&!used[i])
			{
				used[i]=true;
				count++;
				q.push(i);
			}
		}
	}
	return count;
}

int main()
{
	int i,a,b,t=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		init();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a].push_back(b);
			map[b].push_back(a);
		}
		int ans=bfs();
		printf("Case %d: %d/n",++t,ans);
	}
	return 0;
}
