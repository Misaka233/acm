#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a;
        scanf("%I64d",&a);
        long long t1=ceil((1+sqrt(1+4*a))/2)-1;
        printf("%I64d ",t1+a);
        long long k=floor(sqrt(t1+a));
        long long t2=k*(k+1)*(2*k+1)/3+k*(k+1)/2-((k+1)*(k+1)-(t1+a)-1)*k;
        printf("%I64d\n",t2);
    }
    return 0;
}
