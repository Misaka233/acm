#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int v[105];
int main()
{
    memset(v,0,sizeof(v));
    scanf("%d%d",&n,&m);
    while(m--)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int k=max_element(a+1, a + n+1)-a;
        v[k]++;
    }
    printf("%d\n",max_element(v+1, v + n+1)-v);
    return 0;
}
