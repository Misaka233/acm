#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int k,m;
int a[maxn],b[maxn];
int main()
{
    int size_a,size_b;
    scanf("%d%d",&size_a,&size_b);
    scanf("%d%d",&k,&m);
    for(int i=0;i<size_a;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<size_b;i++)
    {
        scanf("%d",&b[i]);
    }
    if(a[k-1]<b[size_b-m])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
