#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long s[50],la[50];
int co,n,m;
bool dfs(long long build,int step,int cur)
{
    if (build == ((long long)1 << n) -1)
		return true;
	if (step == co)
		return false;

	for (int i = cur; i <= n; i++) {
		if (build == (build | s[i]))
			continue;
		if ((build | la[i]) != ((long long)1 << n) -1)
			return false;
		if (dfs(build | s[i], step + 1, cur + 1))
			return true;
	}
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        for(int i=0;i<n;i++)
        {
            s[i+1]=(long long)1<<i;
        }
        int u,v;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            s[u]|=(long long)1<<(v-1);
            s[v]|=(long long)1<<(u-1);
        }
        la[n]=s[n];
        for(int i=n-1;i>0;i--)
        {
            la[i]=la[i+1]|s[i];
        }
        for(co=1;co<=n;co++)
        {
            if(dfs(0,0,1))
            {
                   printf("%d\n",co);
                   break;
            }
        }
    }
    return 0;
}
