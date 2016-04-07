#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
typedef long long LL;
using namespace std;
LL p;
LL A[12],M[12];
LL mod_mul(LL a,LL b,LL mod)
{
    LL ret=0;
    while(b)
    {
        if(b&1) ret=(ret+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ret;
}
LL qpow(LL a,LL b)
{
    LL ans;
    for(ans=1;b;b>>=1,a=a*a%p)
        if(b&1)ans=mod_mul(ans,a,p);
    return ans;
}
LL getc(LL n,LL m)
{
    if(n<m)return 0;
    if(m>n-m)m=n-m;
     LL  s1=1,s2=1;
    for(LL i=0;i<m;i++)
    {
        s1=mod_mul(s1,(n-i),p);
        s2=mod_mul(s2,(i+1),p);
    }
    return mod_mul(s1,qpow(s2,p-2),p);
}
LL lucas(LL n,LL m)
{
    if(m==0)return 1;
    return mod_mul(getc(n%p,m%p),lucas(n/p,m/p),p);
}

LL Extended_Euclid(LL a,LL b,LL &x,LL &y)    //扩展欧几里得算法
{
    LL d;
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    d=Extended_Euclid(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

LL crt(LL a[],LL w[],LL len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数
{
    LL i,d,x,y,m,n,ret;
    ret=0;
    n=1;
    for (i=0;i<len;i++)
        n*=w[i];
    for (i=0;i<len;i++)
    {
        m=n/w[i];
        d=Extended_Euclid(w[i],m,x,y);
        //ret=(ret+y*m*a[i])%n;
        ret=ret%n+mod_mul(mod_mul(y,m,n),a[i],n);
    }
    return (n+ret%n)%n;
}

int main()
{

    LL n, m,k;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        p=1;

        for(LL i=0;i<k;i++)
        {
            scanf("%I64d",&p);
            M[i]=p;
            A[i]=lucas(n, m);
        }

        printf("%I64d\n",crt(A,M,k));
    }
    return 0;
}
