#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,misaka=0,ans=0,mmax=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a==0)
        {
            misaka++;
        }
        else
        {
            misaka--;
            ans++;
        }
        mmax=max(mmax,misaka);
        if(misaka<0) misaka=0;
    }
    printf("%d\n",mmax+ans);
}
