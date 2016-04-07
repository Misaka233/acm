#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[110];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n,i;
        cin>>n;
        for(i=0;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<n-1;j++)
        {
            cout<<a[j]*(i-j-1)<<" ";
        }
        cout<<a[n-1]*(i-n)<<endl;
    }
    return 0;
}
