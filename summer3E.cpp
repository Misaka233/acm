#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long pow(long long a,int n)
{
    long long int z=1;
    long long temp=a;
    while(n)
    {
        if(n&1) z*=temp;
        temp*=temp;
        n>>=1;
    }
    return z;
}

int main()
{
    long long k;
    long long ans;
    while(scanf("%I64d",&k)&&k)
    {
        ans=0;
        long long temp=(long long)sqrt(k);
        if(temp*temp==k)ans+=(temp-1)/2;
        for(int z=3;z<31;z++)
        {
            for(long long x=1;;x++)
            {
                long long u=pow(x,z);
                if(u*2>=k) break;
                for(long long y=x+1;;y++)
                {
                    long long v=pow(y,z);
                    if(u+v+x*y*z>k) break;
                    if(u+v+x*y*z==k) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
