#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
long long  x[10005],p[10005],y[10005],xx[10005],xxcnt;
int main()
{
    long long  a,b,c,n,m,aa,bb,k,s;
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for(i=0;i<n;i++)
            scanf("%I64d",&x[i]);
        for(i=0;i<m;i++)
        {
            scanf("%I64d",&p[i]);
            p[i]--;
        }
        memset(y,0,sizeof(y));
        s=0;
        for(i=0;i<m;i++)
        {
            y[p[i]]=1;
            s+=x[p[i]];
        }
        if(s>k)printf("-1\n");
        else
        {
            xxcnt=0;
            for(i=0;i<n;i++)
                if(!y[i])
                {
                    xx[xxcnt++]=x[i];
                }
            sort(xx,xx+xxcnt);
            a=m;b=1;
            for(i=0;i<xxcnt;i++)
            {
                s+=xx[i];
                if(s>k)
                {
                    printf("%I64d\n",a);
                    b=0;
                    break;
                }
                a++;
            }
            if(b)
            printf("%I64d\n",a);
        }
    }
    return 0;
}
