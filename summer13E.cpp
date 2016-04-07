#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=800007;
const long long mod=1000000007;
long long c[maxn],C[maxn];
bool flag[maxn+5];
int pr[maxn/4];
int susu()
{
    int m=(int)sqrt(maxn+0.5);
    int cnt=0;
    int i;
    flag[0]=flag[1]=true;
    for(i=2;i<=m;i++) if(!flag[i])
    {
        pr[cnt++]=i;
        for(int j=i*i;j<=maxn;j+=i) flag[j]=true;
    }
    for(;i<=maxn;i++) if(!flag[i])
        pr[cnt++]=i;
    return cnt;
}
void f()
{
    susu();
    for(int i=0;i<8000;i++){
        for(int j=i;j<8000;j++){
            for(int k=j;k<8000;k++){
                long long tem=(long long)pr[i]*pr[j]*pr[k];
                if(tem>=maxn) break;
                c[tem]++;
            }
            long long tem=(long long)pr[i]*pr[j];
            if(tem>=maxn) break;
            c[tem]++;
        }
        c[pr[i]]++;
    }
    for(int i=0;i<8000;i++){
        for(int j=i;j<8000;j++){
            if(pr[i]*pr[j]>=maxn) break;
            for(int k=0;k<8000;k++){
                long long tmp=(long long )pr[i]*pr[j]+pr[k];
                if(tmp>=maxn) break;
                c[tmp]++;
            }
        }
    }
    for(int i=0;i<8000;i++){
        for(int j=0;j<8000;j++){
            long long tmp=pr[i]+pr[j];
            if(tmp>=maxn) break;
            C[tmp]++;
        }
    }

}
int main()
{
    f();
    while(~scanf("%d",&n))
    {
        long long ans=0;
        for(int i=0;pr[i]<n;i++){
            ans+=C[n-pr[i]];
            if(n>pr[i]*2 && !flag[n-pr[i]*2])
                ans+=3;
        }
        if(n%3==0 && !flag[n/3]) ans+=5;
        ans/=6;
        long long tt=C[n];
        if(n%2==0 && !flag[n/2]) tt++;
        tt/=2;
        ans=(ans+tt+c[n])%mod;
        cout<<ans<<endl;
    }
    return 0;
}







