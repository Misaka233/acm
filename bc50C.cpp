#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
long long a[100];
long long b[100];
int n;
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    b[1]=1;b[2]=1;b[3]=2;b[4]=3;
    for(int i=5;i<65;i++)
    {
        b[i]=b[i-1]+b[i-3];
    }
    a[1]=1;a[2]=2;a[3]=3;a[4]=5;a[5]=8;
    for(int i=6;i<65;i++)
    {
        a[i]=a[i-1]+b[i-1];
    }
    while(~scanf("%d",&n))
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
