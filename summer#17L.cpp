#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    long long t,a,b;
    scanf("%I64d",&t);
    for(long long cas=1;cas<=t;cas++)
    {
        long long x=0;
        scanf("%I64d%I64d",&a,&b);
        for(long long i=a;i<=b;i++)
        {
            x+=i*i*i;
        }
        printf("Case #%I64d: %I64d\n",cas,x);
    }
    return 0;
}
