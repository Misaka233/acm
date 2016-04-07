#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
double p[maxn];
double a1[maxn];
double a2[maxn];
double b[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&p[i]);
        a1[i]=i;
        a2[i]=i+1;
    }
    double l=9;
    double r=99999999999;
    for(int i=1;i<=n;i++)
    {
        l=max(l,10*p[i]/a1[i]);
        r=min(r,(10*p[i]+10.0)/a1[i]);
    }
    //cout<<l<<" "<<r<<endl;
    double ll=((n+1)*r-10.0-1e-6)/10.0;
    double rr=((n+1)*l)/10.0;
    //cout<<ll<<" "<<rr;
    double lls=ceil(ll);
    double rrs=floor(rr);
    if(lls==rrs)
    {
        cout<<"unique"<<endl;
        printf("%.0lf",rrs);
    }
    else
        cout<<"not unique"<<endl;
    return 0;
}
