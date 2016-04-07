//num[i][j] 表示从i 倒水给 j的 量
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct misaka
{
	double num[25][25];
    misaka()
	{
		for(int i = 0; i < 25; i++)
            for(int j = 0; j < 25; j++)
                num[i][j] = 0;
	}
};
misaka in, un, ans;
double a[25];
misaka mal(misaka a, misaka b, int n)
{
	misaka r;
	for(int i = 1; i <= n; i++)
	for(int k = 1; k <= n; k++)
	{
		if( a.num[i][k])
		for(int j = 1; j <= n; j++)
		{
			if( b.num[k][j] )
			{
				r.num[i][j] = r.num[i][j] + a.num[i][k] * b.num[k][j];
			}
		}
	}
	return r;
}
misaka mul(misaka a, misaka b, int k, int n)
{
	while(k)
	{
		if(k&1)
		{
			b = mal(a, b, n);
			k--;
		}
		else
		{
			a = mal(a, a, n);
			k >>= 1;
		}
	}
	return b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                in.num[i][j] = 0;
                un.num[i][j] = ( i == j);
            }
		int k, y;
		double p;
		for(int i = 1; i <= n; i++)
		{
			cin>>k;
            if(k == 0)
			{
				in.num[i][i] = 1;
				continue;
			}
			p = 1.0/k;
			while(k--)
			{
				cin>>y;
				in.num[i][y] = p;
			}
		}
		int m;
		cin>>m;
		ans = mul(in, un, m, n);
		double sum;
		for(int i = 1; i <= n; i++)
		{
			sum = 0;
			for(int j = 1; j <= n; j++)
			{
				sum += ans.num[j][i] *a[j];
			}
			if(i!= n)
				printf("%0.2lf ", sum);
			else
				printf("%0.2lf\n", sum);
		}

	}
	return 0;
}
