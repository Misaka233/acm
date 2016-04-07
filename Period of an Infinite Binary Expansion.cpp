#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long fact[100000], pf;


long long Euler ( long long n )
{
    long long ret = n, i;
    for ( i = 2; i * i <= n; i++ )
    {
        if ( n % i == 0 )
        {
            n /= i;
            ret = ret - ret / i;
            while ( n % i == 0 )
                n /= i;
        }
    }
    if ( n > 1 )
        ret = ret - ret / n;
    return ret;
}

long long gcd ( long long a, long long b )
{
    long long c;
    while ( b != 0 )
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long mod_mult ( long long a, long long b, long long n )
{
    long long ret = 0;
    a = a % n;
    while ( b >= 1 )
    {
        if ( b & 1 )
        {
            ret += a;
            if ( ret >= n ) ret -= n;
        }
        a <<= 1;
        if ( a >= n ) a -= n;
        b >>= 1;
    }
    return ret;
}

long long mod_exp ( long long a, long long b, long long n )
{
    long long ret = 1;
    a = a % n;
    while ( b >= 1 )
    {
        if ( b & 1 )
            ret = mod_mult(ret,a,n);
        a = mod_mult(a,a,n);
        b >>= 1;
    }
    return ret;
}

void factor ( long long x )
{
    pf = 0;
    for ( long long i = 2; i * i <= x; i++ )
        if ( x % i == 0 )
            fact[pf++] = i, fact[pf++] = x / i;
}

int main()
{
    long long eul;
    long long p, q, d, cnt, cs = 0;
    while ( scanf("%I64d/%I64d",&p,&q) != EOF )
    {
        if(!p){ printf("Case #%I64d: 1,1 \n",++cs);continue; }
        d = gcd(p,q);
        p /= d; q /= d;
        cnt = 1;
        while ( q % 2 == 0 ) { q >>= 1; cnt++; }

        eul = Euler(q);
        factor(eul);
        sort(fact,fact+pf);
        fact[pf++] = eul; long long i;
        for ( i = 0; i < pf; i++ )
            if ( mod_exp (2, fact[i], q) == 1 ) break;
        printf("Case #%I64d: %I64d,%I64d\n",++cs,cnt,fact[i]);
    }
    return 0;
}
/*
我们可以观察一下1/10这组数据，按照二进制转换法(乘二法)，我们可以得到：
1/10  2/10 4/10 8/10 16/10 32/10 ...
然后都分子都尽可能减去10，得到：
1/10  2/10 4/10 8/10 6/10 2/10 ...
这时候，发现出现了重复，那么这个重复就是我们要求的最小循环。
抽象出模型如下：对p/q
首先p'=p/gcd(p,q)
q'=q/gcd(p,q);

然后我们就是求p'*2^i == p'*2^j (mod q')   (“==”表示同余,i<j)
经过变换得到：
p'*2^i*(2^(j-i)-1) ==0 (mod q')
也就是 q' | p'*2^i*(2^(j-i)-1)
由于gcd(p',q')=1,
得到： q' | 2^i*(2^(j-i)-1)
因为2^(j-i)-1为奇数，所以q'有多少个2的幂，i就是多少，而且i就是循环开始位置的前一位。
那么令q''为q'除去2的幂之后的数
此时 q'' | 2^(j-i)-1
也就是求出x,使得 2^x ==1 (mod q'')

欧拉定理：若a与p互质，则a^Φ(p) == 1 (modp)

所以2^x ==1 (mod q'')   必定存在解。

现在我要求的是最小循环节。又已知，若a,p互质，且a^x == 1 (mod p)， 那么必定有a | Φ(p)。

至此，只需要从小到大枚举Φ(p）的因子即可。
*/
