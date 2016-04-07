#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        string s;
        cin>>s;
        if(s.size()%2==0) cout<<"Case "<<i<<": Even"<<endl;
        if(s.size()%2==1) cout<<"Case "<<i<<": Odd"<<endl;
    }
    return 0;
}
