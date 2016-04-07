#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
struct misaka{
    long long x;
    long long y;
    long long w;
    long long kk;
}a[100005];
int b[100005];
int n,cas;
int main()
{
    cas=0;
    while(~scanf("%d",&n)&&n)
    {
        cas++;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
            a[i].kk=1;
        }
        printf("Case #%d:\n",cas);
        int m;
        int kkk;
        scanf("%d",&kkk);
            while(kkk--)
            {
                 scanf("%d",&m);
                int co=0;
                for(int i=1;i<=n;i++)
                {
                    if(a[i].kk!=0)
                    {
                        int x=abs(a[i].x-a[m].x);
                        int y=abs(a[i].y-a[m].y);
                        if((a[m].w>=x+y))
                        {
                            a[i].kk=0;
                            co++;
                        }
                    }

                }

                printf("%d\n",co);
            }

    }
    return 0;
}
//
