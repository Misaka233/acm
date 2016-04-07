#include<iostream>
#include<cstdio>
using namespace std;
const int N=210000;
int a[N], p[N];
int main()
{
    int n;
    scanf("%d", &n);
    int i, b;
    for (i=0;i<n;i++)
        scanf("%d", &a[i]);
    for (i=0;i<n;i++)
    {
        cin>>b;
        p[b]=i+1;
    }
    for (i=1;i<n;i++)
        if (p[a[i]]<p[a[i-1]]) break;
    int ans=n-i;
    printf("%d\n", ans);
    return 0;
}
