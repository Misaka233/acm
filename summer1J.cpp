#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
const int maxn=1000100;
pair<long long int,long long int>P[maxn];
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int p;
        cin>>p;
        memset(P,0,sizeof(P));
        for(int i=0;i<p;i++)
            cin>>P[i].first>>P[i].second;
        sort(P,P+p);
        unsigned long long  ans=0,ans2=1;
        unsigned long long  sum=0;
        for(int i=0;i<p;i++)
        {
            sum+=P[i].second;
            if(i!=p-1)
            {
                ans2=(ans2*(P[i].second+1));
                if(ans2>mod) ans2%=mod;
            }
            ans+=P[i].second*sum;
        }
        cout<<"Case "<<cas<<": "<<ans<<" "<<ans2%mod<<endl;
    }
    return 0;
}

