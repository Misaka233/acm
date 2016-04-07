#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int mmin=3000000000;
    int mmax=-1;
    for(int i=0;i<n;i++)
    {
        if(i==0) {mmin=a[1]-a[0];mmax=a[n-1]-a[0];}
        else if(i==n-1) {mmin=a[n-1]-a[n-2];mmax=a[n-1]-a[0];}
        else {mmin=min(a[i]-a[i-1],a[i+1]-a[i]);mmax=max(a[i]-a[0],a[n-1]-a[i]);}
        printf("%d %d\n",mmin,mmax);
        mmin=3000000000;
        mmax=-1;
    }
    return 0;
}
