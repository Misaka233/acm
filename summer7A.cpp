#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f(double a)
{
    if(a>=1.000) return 0;
    else if(a>=0.400) return 1;
    else if(a>=0.160) return 2;
    else if(a>=0.063) return 3;
    else if(a>=0.025) return 4;
    else if(a>=0.010) return 5;
    else if(a>=0.004) return 6;
    else return 7;
}
int main()
{
    int t,cas;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        double n;
        cin>>n;
        int ans=f(n);
        if(ans==0) printf("Case #%d: Too Bright\n",cas);
        else if(ans==7) printf("Case #%d: Invisible\n",cas);
        else printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
