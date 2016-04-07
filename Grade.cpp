#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int a[maxn];
int main()
{
    int n,s,t,w;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        int mmax=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&w);
            int ww=10000-(100-w)*(100-w);
            a[ww]++;
            mmax=a[ww]>mmax?a[ww]:mmax;
        }
        printf("Case #%d:\n",cas);
        int co=0;int fir=0;
        for(int i=0;i<=maxn;i++)
        {
            if(a[i]==mmax) co++;
            if(a[i]&&a[i]!=mmax)
                {co=-1;break;}
        }
        if(co>1) printf("Bad Mushroom\n");
        else
        {
            for(int i=0;i<=maxn;i++)
            {
                if(a[i]==mmax)
                {
                    if(fir) printf(" ");
                    printf("%d",i);
                    fir=1;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
