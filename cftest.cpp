#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
//lson和rson分辨表示结点的左儿子和右儿子
//rt表示当前子树的根(root),也就是当前所在的结点
#define INF 0x3fffffff
__int64 mmin[5000047];
__int64 col[5000047];
__int64 MIN(__int64 a, __int64 b)
{
	if( a < b)
		return a;
	return b;
}
void pushup(int rt)
{
	//sum[rt] = sum[rt<<1] + sum[rt<<1|1];
	mmin[rt]=MIN(mmin[rt<<1], mmin[rt<<1|1]);
}
void pushdown(int rt, int m)
{
	if(col[rt])
	{
		col[rt<<1]+=col[rt];
		col[rt<<1|1]+=col[rt];
		mmin[rt<<1]+=col[rt];
		mmin[rt<<1|1]+=col[rt];
		col[rt]=0;
	}
}
void build(int l, int r, int rt)
{
	col[rt]=0;
	if(l==r)
	{
		scanf("%I64d", &mmin[rt]);
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L, int R, int v, int l, int r, int rt)
{
	if(L<=l && r<=R)
	{
		col[rt]+=v;
		mmin[rt]+=v;
		return ;
	}
	pushdown(rt, r-l+1);
	int m=(l+r)>>1;
	if(L<=m)
		update(L, R, v, lson);
	if(R>m)
		update(L, R, v, rson);
	pushup(rt);
}
__int64 query(int L, int R, int l, int r, int rt)
{//查询区间[L，R]中的最小值
	if(L<=l && r<=R)//当前结点完全包含在查询区间内
		return mmin[rt];
	pushdown(rt, r-l+1);
	int m=(l+r)>>1;
	__int64 ret=INF;
	if(L<=m)//往左走
		ret=MIN(ret, query(L, R, lson));
	if(R>m)//往右走
		ret=MIN(ret, query(L, R, rson));
	return ret;
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
		a++;//将区间转换为是1到n
		b++;
		if(a<=b)
		{
			if(op==' ')//意味着是输入三个数的操作
			{
				scanf("%d", &c);
				if(c==0)
					continue;
				update(a, b, c, 1, n, 1);
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
				update(a, n, c, 1, n, 1);//拆分区间为a到n和1到b
				update(1, b, c, 1, n, 1);
			}
			else
				printf("%I64d\n", MIN(query(a, n, 1, n, 1), query(1, b, 1, n, 1)));
		}
	}
	return 0;
}
