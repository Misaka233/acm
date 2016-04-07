#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX_N=100005;
int s[MAX_N];
int a[MAX_N];
int n,m,k;
int f(int a[],int b[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if((a[i]==a[i+1]&&b[i]==b[i+1])||(a[i]>a[i+1]&&b[i]>b[i+1])||(a[i]<a[i+1]&&b[i]<b[i+1]))
            continue;
        else break;
    }
    if(i==n-1) return 1;
    else return 0;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i<n-m+1;)
        {
            if(f(a,&s[i],m))
            {
                i+=m;ans++;
            }
            else i++;
        }
        cout<<ans<<endl;
    }
}
