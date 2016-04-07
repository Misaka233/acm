#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int n,k,l,ans;
int a[12],b[14],c[12][12],g[12],G[12];
int f()
{
    int i,j;
    memset(b,0,sizeof(b));
    for(i=0;i<n-1;i++) b[a[i]]++;
    if(b[k]==0) return 0;
    int ans=1;
    for(i=1;i<n-1;i++)
    {
        if(a[i]!=k+1)
        {
            G[0]=1;
            for(j=1;j<=i;j++)
            {
                int tm;
                if(a[i]==a[j-1]) tm=0;
                else tm=a[i]-a[j-1]-1;
                G[j]=(long long)G[j-1]*(l-tm)%mod;
            }
            g[i-1]=l-a[i];
            for(j=i-2;j>=0;j--)
                g[j]=(long long)g[j+1]*(l-a[i]+a[j+1])%mod;
            int tm=G[i];
            for(j=0;j<i;j++)
            {
                if(a[j]!=a[i]) tm=(tm+(long long)G[j]*g[j])%mod;

            }
            ans=(long long)ans*tm%mod;
        }
        else{
            int tm=l-k;
            for(j=0;j<i;j++)
            {
                tm=(long long)tm*(l-max(k-a[j],0))%mod;
            }
            ans=(long long)ans*tm%mod;
        }
    }
    b[k]--;
    int p=1,re=n-2;
    for(i=0;i<=k+1;i++)
    {
        p=(long long)p*c[re][b[i]]%mod;
        re-=b[i];
    }
    ans=(long long)ans*p%mod;
    return ans;
}
void dfs(int i,int j)
{
    if(i==n-1) ans=(ans+f())%mod;
    else{
        int tm=min(l,k+1);
        for(;j<=tm;j++)
        {
            a[i]=j;
            dfs(i+1,j);
        }
    }

}

int main()
{
    int t;

    memset(c,0,sizeof(c));
	c[0][0]=1;
	for (int i=1;i<12;i++)
    {
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
     cin>>t;
    while(t--)
    {
        cin>>n>>k>>l;
        ans=0;
        if(n==0) ans=0;
        else if(n==1&&k==0) ans=1;
        else if(n==1) ans=0;
        else dfs(0,1);
        cout<<ans<<endl;
    }
    return 0;
}
