#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100010];
    scanf("%d",&n);
    int mmax=-1;
    int co=1;
    a[0]=2000000000;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=a[i-1])
        {
                co++;
        }
        else
        {
            co=1;
        }
        mmax=max(mmax,co);
    }
    printf("%d\n",mmax);
    return 0;
}
