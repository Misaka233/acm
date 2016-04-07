#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n;string s;
    int co1=0,co2=0;
    cin>>n>>s;
    if(s[n-1]=='0') s[n]='1';
    else s[n]='0';
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i+1]) co1++;
        else co2++;
    }
    cout<<co2+min(2,co1);
    return 0;
}
