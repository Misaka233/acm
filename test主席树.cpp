#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#define LL long long
#define _LL __int64
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int n,s;
int a[maxn],b[maxn],c[maxn];

//求置换的长度a
int solve()
{
	int cnt = 0,i;
	while(1)
	{
		for(i = 1; i <= n; i++)
			b[i] = c[c[i]];
		cnt++;
		for(i = 1; i <= n; i++)
			if(a[i] != b[i])
				break;

		if(i > n)
			break;
		for(i = 1; i <= n; i++)
			c[i] = b[i];
	}
	return cnt;
}

int main()
{
	while(~scanf("%d %d",&n,&s))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
			b[i] = a[i];
			c[i] = a[i];
		}

		int cnt = solve();
		s %= cnt;
		s = cnt - s;
		while(s--)
		{
			for(int i = 1; i <= n; i++)
				b[i] = a[a[i]];
			for(int i = 1; i <= n; i++)
				a[i] = b[i];
		}
		for(int i = 1; i <= n; i++)
			printf("%d\n",b[i]);

	}
	return 0;
}
