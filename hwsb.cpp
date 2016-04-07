#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
int a[100010];
bool isok(int n,int m,ll x)
{
	ll t=x;
	for(int i=0;i<n;i++)
	{
		int re=a[i];
		ll t1=t-i-1;
		if(t1<0)
		{
			if(m==0)
				return 0;
			t1=x-i-1;
			t=x;
			m--;
		}
		if(re>0)
		{
			if(t1>=re)
				t-=re;
			else
			{
				re-=t1;
				t1=x-i-1;
				t=x;
				int t2=re/t1;
				re-=t2*t1;
				if(re>0)
				{
					t2++;
					t-=re;
				}
				else
					t=0;
				m-=t2;
				if(m<0)
					return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=n-1;i>-1;i--)
		if(a[i]!=0)
		{
			n=i+1;
			break;
		}
	ll l=n+1,r=ll(1e15);
	while(l<=r)
	{
		ll md=l+r>>1;
		if(isok(n,m-1,md))
			r=md-1;
		else
			l=md+1;
	}
	cout<<l<<endl;
	}

}
