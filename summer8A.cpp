#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int v[30];
int k;
bool cmp(int a,int b)
{
    return a>b;
}
long long f(long long p,long long q)
{
    q=min(q,p-q);
	long long i;
	long long fac1=1;
	for (i=p;i>=p+1-q;i--)
		fac1*=i;

	long long fac2=1;
	for (i=1;i<=q;i++)
		fac2*=i;

	return (fac1/fac2);
}
int main()
{
    string s;
    long long k;
    cin>>s;
     cin>>k;
    memset(v,0,sizeof(v));
    for(int i=0;i<s.size();i++)
    {
        v[s[i]-'a'+1]++;
    }
    sort(v,v+26,cmp);
    long long kind=0;
    long long len=s.size();
    for (int i=0;i<26;i++)
	{
		if (v[i])
		kind++;
		else	break;
	}
    if (k>=kind)
    {
        cout<<len<<" "<<1<<endl;
        return 0;
    }
    else
    {
            int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=v[i];
    }
    long long c1=0,c2=0;
    long long temp=v[k-1];
    for(int i=0;i<k;i++)
    {
        if(v[i]==temp) c1++;
    }
    for(int i=0;i<26;i++)
    {
        if(v[i]==temp) c2++;
    }
    long long ans=f(c1,c2);
    cout<<sum<<" "<<ans<<endl;
    }

    return 0;
}
