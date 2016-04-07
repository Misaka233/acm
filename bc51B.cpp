#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int k,b,x0,p;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&k,&b,&x0,&p);
        int x,xx;
        x=(k*x0+b)%p;
        int ans=1;
        int co=0;
        while(x!=x0)
        {
            xx=(k*x+b)%p;
            if(xx==x)
            {
                break;
            }
            if(k*x+b>=p) co++;
            if(co>=1000000000) break;
            x=(k*x+b)%p;

            ans++;
        }
              cout<<co<<endl;
       if(x==x0) printf("%d\n",ans);


       else printf("-1\n");
    }
}
