#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
long long gcd(long a,long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    long long l,w;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%I64d%I64d",&l,&w);
        long long x=gcd(l,w);
        printf("Case #%d: %I64d\n",cas,x);
    }
}
