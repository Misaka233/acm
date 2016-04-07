#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_size 120000
long long v[Max_size];
long long d[Max_size];
long long p[Max_size];
long long sum[Max_size];
long long n,m;
int find_max(int a,int b)
{
	return a>b?a:b;
}
void init()
{
	memset(d,0,sizeof(d));
	memset(sum,0,sizeof(sum));
	memset(p,0,sizeof(p));
}
int lowbit(int x)
{
	return x&(-x);
}
int update(int x)
{
	int res=0;
	res-=p[x];
	while(x<=Max_size)
	{
		res+=d[x];
		x+=lowbit(x);
	}
	return res;
}
void setline(int x)
{
	while(x>0)
	{
		++d[x];
		x-=lowbit(x);
	}
}
int main()
{
	int T;
	int i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		init();
		for(i=0;i<n;i++)
		{
			sum[i+1]=sum[i]+update(v[i]);
			setline(v[i]);
			++p[v[i]];
		}
		int ans=sum[n];
		int max=0;
		for(i=m;i<=n;i++)
		{
			max=find_max(sum[i]-sum[i-m],max);
		}
		printf("%d\n",ans-max);
	}
	return 0;
}
