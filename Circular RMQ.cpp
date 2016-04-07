#include<bits/stdc++.h>
using namespace std;
const int maxn=5000500;
long long mmin[maxn];
long long bilibili[maxn];
long long MIN(long long a,long long b)
{
    if(a<b)
        return a;
    return b;
}
void up(int misaka)
{
    mmin[misaka]=MIN(mmin[misaka<<1],mmin[misaka<<1|1]);
}
void down(int misaka,int Arthas)
{
    if(bilibili[misaka])
    {
        bilibili[misaka<<1]+=bilibili[misaka];
        bilibili[misaka<<1|1]+=bilibili[misaka];
        mmin[misaka<<1]+=bilibili[misaka];
        mmin[misaka<<1|1]+=bilibili[misaka];
        bilibili[misaka]=0;
    }
}
void build(int l,int r,int misaka)
{
    bilibili[misaka]=0;
    if(l==r)
    {
        scanf("%I64d",&mmin[misaka]);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,misaka<<1);
    build(m+1,r,misaka<<1|1);
    up(misaka);
}
void upset(int L,int R,int v,int l,int r,int misaka)
{
    if(L<=l&&r<=R)
    {
        bilibili[misaka]+=v;
        mmin[misaka]+=v;
        return ;
    }
    down(misaka,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)
        upset(L,R,v,l,m,misaka<<1);
    if(R>m)
        upset(L,R,v,m+1,r,misaka<<1|1);
    up(misaka);
}
long long query(int L, int R, int l, int r, int misaka)
{
	if(L<=l && r<=R)
		return mmin[misaka];
	down(misaka, r-l+1);
	int m=(l+r)>>1;
	long long res=9999999999;
	if(L<=m)
		res=MIN(res, query(L, R, l , m , misaka << 1));
	if(R>m)
		res=MIN(res, query(L, R, m + 1 , r , misaka << 1 | 1));
	return res;
}
int main()
{
	int n, m, a, b, c;
	char op;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d%c", &a, &b, &op);
		a++;
		b++;
		if(a<=b)
		{
			if(op==' ')
			{
				scanf("%d", &c);
				if(c==0)
					continue;
				upset(a, b, c, 1, n, 1);
			}
			else
				printf("%I64d\n", query(a, b, 1, n, 1));
		}
		else
		{
			if(op==' ')
			{
				scanf("%d", &c);
				if(c==0)
					continue;
				upset(a, n, c, 1, n, 1);
				upset(1, b, c, 1, n, 1);
			}
			else
				printf("%I64d\n", MIN(query(a, n, 1, n, 1), query(1, b, 1, n, 1)));
		}
	}
	return 0;
}
