
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

long long f(long long a)
{
	long long ans=0;
	if (a<=4) return 0;
	ans=a/2-2;
	long long t=sqrt(a);
	if(t%2==0) return ans;
	else return ans+1;
}

int main()
{
	long long x,y;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
        cout<<f(y)-f(x-1)<<endl;

	}
	return 0;
}

