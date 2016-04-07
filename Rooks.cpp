#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=105;
char map1[maxn][maxn];
int map2[maxn][maxn];
int link[maxn];
bool flag[maxn];
vector<int> G[maxn];
int deg[maxn];
int n,rook;
bool dfs(int x)
{
	for (int i = 0 ; i < G[x].size() ; i++) if (!flag[G[x][i]])
	{
		int y = G[x][i];
		flag[y] = true;
		if (link[y]==-1 || dfs(link[y]))
		{
			link[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(map1,0,sizeof(map1));
        scanf("%d",&n);
        rook=0;
        memset(deg,0,sizeof(deg));
        for(int i=0;i<n;i++)
        {
            G[i].clear();
            scanf("%s",map1[i]);
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(map1[i][j]=='*')
                {
                    cnt++;
                    G[i].push_back(j);
                    deg[j]++;
                }
            }
            rook=max(rook,cnt);
        }
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=n-1;j>=0;j--)
            {
                if(map1[j][i]=='*')
                {
                    cnt++;
                }
            }
            rook=max(rook,cnt);
        }
        for(int i=0;i<n;i++)  if (G[i].size()<rook)
        {
            for(int j=0;j<n&&G[i].size()<rook;j++)
            {
                if(deg[j]<rook)
                {
                    while(deg[j] < rook && G[i].size() < rook)
                    {
                        G[i].push_back(j);
                        deg[j]++;
                    }
                }
            }
        }
        printf("%d\n",rook);
        memset(map2,0,sizeof(map2));
        int color=0;
        while(color<rook)
        {
            color++;
            memset(link,-1,sizeof(link));
        for(int i=0;i<n;i++)
        {
            memset(flag,0,sizeof(flag));
            dfs(i);
        }
        for(int i=0;i<n;i++)
        {
            int r=link[i],c=i;
            if(map1[r][c]=='*') map2[r][c]=color;
            for(int j=0;j<G[r].size();j++)
            {
                if(G[r][j]==c)
                {
                    G[r].erase(G[r].begin()+j);
                    break;
                }
            }
        }
        }

        for(int i=0;i<n;i++)
        {
            printf("%d",map2[i][0]);
            for(int j=1;j<n;j++)
            {
                printf(" %d",map2[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
