#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
 bool isprime[1000010];
int prime[1000010];
void Prime()
{

    fill(isprime, isprime+1000001, 1);
    int a=sqrt(1000010);
    for (int i=2; i<=a; i++)
    {
        if (isprime[i])
        {
            for (int k=2*i; k<=1000000; k+=i)
            {
                isprime[k]=0;
            }
        }
    }
    int k=1;
    for (int i=2; i<=1000010; i++)
    {
        if (isprime[i])
        {
            prime[k++]=i;
        }
    }
}
int main()
{
    Prime();
    prime[0]=100;
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int n;
        scanf("%d",&n);
        int q=sqrt(n);
        int temp=lower_bound(prime+1, prime+10010, q)-prime;
        if (n==prime[temp]*prime[temp])
        {
            printf("%d\n",n);
        }
        else if(abs(n-prime[temp]*prime[temp])>abs(n-prime[temp-1]*prime[temp-1]))
        {
            printf("%d\n",prime[temp-1]*prime[temp-1]);
        }
        else
        {
            printf("%d\n",prime[temp]*prime[temp]);
        }
    }
    return 0;
}
