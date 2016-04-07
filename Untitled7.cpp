#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxn=500010;
LL a[maxn],sum[maxn],tot[maxn];
LL mod_mul(LL a,LL b)
{
    LL ans = 1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
const LL inv  = mod_mul(2,mod-2);
int main()
{

    a[1]=1;
    sum[0]=0;
    sum[1]=1;
    for(int i=2;i<maxn;i++)
    {
        a[i]=a[i-a[a[i-1]]]+1;
        sum[i]=sum[i-1]+a[i];
    }
    tot[0]=0;
    for(int i=1;i<maxn;i++)
    {
        tot[i]=tot[i-1];
        LL tmp = (sum[i-1]+1+sum[i])*a[i]%mod*(LL)i%mod*inv%mod;
        tot[i]=(tot[i]+tmp)%mod;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        scanf("%I64d",&n);
        int pos = lower_bound(sum,sum+maxn,n)-sum;
        if(sum[pos]==n) printf("%I64d\n",tot[pos]);
        else
        {
            pos--;
            LL num = tot[pos];
            num = (num+(pos+1)*(n+sum[pos]+1)%mod*(n-sum[pos])%mod*inv%mod)%mod;
            printf("%I64d\n",num);
        }
    }
    return 0;
}
