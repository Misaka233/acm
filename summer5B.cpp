#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int lianxu(string& s)
{
    int co=0,sta=0;
    for(int i=0;i<s.size();i++)
    {
        if(sta==0)
        {
            if(s[i]=='*')
            {
                sta=1;
                co++;
            }
        }
        else if(sta==1)
        {
            if(s[i]=='*') co++;
            else sta=2;
        }
        else if(sta==2)
        {
            if(s[i]=='*') return -1;
        }
    }
    return co;
}
int f(int a, int b, int s) {
	if (a < s || b < s) {
		return 0;
	}
	if (a == s && b == s) {
		return 1;
	}
	return 2;
}
int main()
{
    string st;
    int n,m,s,k,co;
    cin>>m>>n>>s>>k;
    cin>>st;
    int lian=lianxu(st);
    if(lian==0)
    {
        int left = k - 1;
		int right = m - k;
		co = f(left, n, s) + f(right, n, s);
    }
    else if(lian!=s) co=0;
    else
    {
        if(s==1||s==m||k==1||k==m)
            co=1;
        else co=2;
    }
    if(co==0) cout<<"Impossible"<<endl;
    else if(co==1) cout<<"Unique"<<endl;
    else cout<<"Ambiguous"<<endl;
    return 0;
}
