
#include<iostream>
#include<cmath>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<utility>
#include<stdio.h>
using namespace std;
#define LL		long long
#define mset(a,b)	memset(a,b,sizeof a)

const LL p=1000000007;
const int maxn=10011;
LL b,q,a,d,m,n;
LL invq;
LL expp2;
LL C[maxn];
LL invv[maxn];

LL gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b)  {d=a;x=1;y=0;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL inv(LL a)
{
    LL d,x,y;
    gcd(a,p,d,x,y);
    return d==1?(x+p)%p:-1;
}

LL getinv()
{
    invv[1]=1;
    for(int i=2;i<maxn;i++)
    {
        invv[i]=(p-p/i)*invv[p%i]%p;
    }
}

LL exp_mod(LL a, LL b) {
    LL res = 1;
    while(b != 0) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}


LL Comb(LL a, LL b) {
    if(a < b)   return 0;
    if(a == b)  return 1;
    if(b > a - b)   b = a - b;

    LL ans = 1, ca = 1, cb = 1;
    for(LL i = 0; i < b; ++i) {
        ca = (ca * (a - i))%p;
        cb = (cb * (b - i))%p;
    }
    ans = (ca*exp_mod(cb, p - 2)) % p;
    return ans;
}

LL Lucas(int n, int m) {
     LL ans = 1;

     while(n&&m&&ans)
    {
        ans = (ans*Comb(n%p, m%p)) % p;
        n /= p;
        m /= p;
     }
     return ans;
}

void getC()
{
    C[0]=1;
    C[1]=(m+1)%p;
    for(int i=2;i<n+3;i++)
    {
        C[i]=(((m+i)*C[i-1])%p)*invv[i];
        C[i]%=p;
        if(C[i]<0)  C[i]+=p;
    }
}

LL solve()
{
    invq=inv(q-1);
    LL ans;
    LL sm;
    if(q==1)
        sm=(b*Lucas(m+n+1,n+1))%p;
    else{
        getC();
        LL sp=(q*((exp_mod(q,m+1)-1+p)%p)%p*invq%p*invq)%p-(m+1)*invq%p;
        sp%=p;
        if(sp<0)    sp+=p;
        sm=sp;
        for(int i=2;i<n+1;i++)
        {
            sm=(((q*sm)%p*invq)%p-(C[i]*invq)%p+p)%p;
        }
        sm=(sm*b)%p;
        if(sm<0)    sm+=p;
    }
    ans=sm;
    LL tmp=(a*Lucas(m+n+1,m+1))%p;
    ans+=tmp;
    tmp=(d*Lucas(m+n+1,m+2))%p;
    ans+=tmp;
    ans%=p;
    if(ans<0)   ans+=p;
    return ans;
}

int main()
{
    int t,cas=1;
    getinv();
    scanf("%d",&t);
    while(t--)
    {
        LL ans;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&b,&q,&a,&d,&n,&m);
        b%=p;q%=p;a%=p;d%=p;
        m--;n--;
        ans=solve();
        printf("Case #%d: %I64d\n",cas++,ans);
    }
}
//Ans(n,m)=∑1→n C(n+m−i,n−i)×ai+∑1→m C(n+m−i,m−i)×bi

