#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int prime[maxn+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
bool notprime[1000010];
int prime2[1000010];
void getPrime2(int L,int R)
{
    memset(notprime,false,sizeof(notprime));
    if(L<2) L=2;
    for(int i=1;i<=prime[0]&&(long long)prime[i]*prime[i]<=R;i++)
    {
        int s=L/prime[i]+(L%prime[i]>0);
        if(s==1)s=2;
        for(int j=s;(long long)j*prime[i]<=R;j++)
        if((long long)j*prime[i]>=L)
        notprime[j*prime[i]-L]=true;
    }
    prime2[0]=0;
    for(int i=0;i<=R-L;i++)
        if(!notprime[i])
            prime2[++prime2[0]]=i+L;
}
int main()
{
    getPrime();
    int L,U;
    while(~scanf("%d%d",&L,&U))
    {
        getPrime2(L,U);
        for(int i=1;i<=prime2[0];i++)
        {
            printf("%d ",prime2[i]);
        }
    }
    return 0;
}
