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
        long long int a,b,c=0;
        cin>>a>>b;
        while(a>b)
        {
            a=a/2+1;
            c++;
        }
       cout<<"Case "<<i<<": "<<c<<endl;
    }
    return 0;
}
