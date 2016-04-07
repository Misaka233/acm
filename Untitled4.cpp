#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
typedef unsigned long long LL;
using namespace std;

LL exp_mod(LL a, LL b, LL p) {
    LL res = 1;
    while(b != 0) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

LL Comb(LL a, LL b, LL p) {
    if(a < b)   return 0;
    if(a == b)  return 1;
    if(b > a - b)   b = a - b;

    LL ans = 1, ca = 1, cb = 1;
    for(LL i = 0; i < b; ++i) {
        ca = (ca * (a - i))%p;
        cb = (cb * (b - i))%p;
    }
    ans = (ca*exp_mod(cb, p - 2, p)) % p;

    return ans;

}

LL Lucas(LL n, LL m, LL p) {
     LL ans = 1;

     while(n&&m&&ans) {
        ans = (ans*Comb(n%p, m%p, p)) % p;
        cout<<ans<<" ";
        n /= p;
        m /= p;

     }
    //cout<<ans<<" ";
     return ans;
}
LL extend_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        LL r=extend_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
LL crt(LL a[],LL m[],LL n)
{
    LL M=1;
    for(LL i=0;i<n;i++) M*=m[i];
    LL ret=0;
    for(LL i=0;i<n;++i)
    {
        LL x,y;
        LL tm=M/m[i];
        extend_gcd(tm,m[i],x,y);
        ret=(ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
LL A[12],M[12];
int main()
{

    LL n, m, p,k,pp;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        p=1;

        for(LL i=0;i<k;i++)
        {
            scanf("%I64d",&pp);
            M[i]=pp;
            A[i]=Lucas(n, m, pp);
        }
        if(m==n||m==0)
        {
            cout<<"1"<<endl;
            break;
        }
        printf("%I64d\n",crt(A,M,k));
    }
    return 0;
}
