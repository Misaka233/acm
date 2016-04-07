#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
int a[maxn];
int b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,ca=0,cb=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b,b+n);
        for(int i=0;i<m;i++)
        {
            ca+=a[i];
            cb+=b[n-i-1];
        }
        if(ca>cb) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
