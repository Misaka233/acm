#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int N=105;
const int M=1001;
struct misaka
{
    int a,b,c;
} e[M];
bool cmp(misaka a,misaka b)
{
    return a.c<b.c;
}
int n,m,mod;
long long  f[N],U[N],flag[N];
long long G[N][N],C[N][N];
vector<int>V[N];
int find(int x,long long f[])
{
    if(x==f[x])
        return x;
    else
        return find(f[x],f);
}

long long det(long long a[][N],int n)
{
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                a[i][j]%=mod;
            }
        }
    int re=1;
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            while(a[j][i])
            {
                int t=a[i][i]/a[j][i];
                for(int k=i; k<n; k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(int k=i; k<n; k++)
                    swap(a[i][k],a[j][k]);
                re=-re;
            }
        if(a[i][i]==0)
            return 0;
        re=re*a[i][i]%mod;
    }
    return (re+mod)%mod;
}

int main()
{
    while(scanf("%d %d %d",&n,&m,&mod)&&n)
    {
        memset(G,0,sizeof(G));
        for(int i=1; i<=n; i++)
            V[i].clear();
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
        sort(e,e+m,cmp);
    for(int i=1; i<=n; i++)
    {
        f[i]=i;
        flag[i]=0;
    }
    long long E=-1,ans=1;
    for(int k=0; k<=m; k++)
    {
        if(e[k].c!=E||k==m)
        {
            for(int i=1; i<=n; i++)
            {
                if(flag[i])
                {
                    long long u=find(i,U);
                    V[u].push_back(i);
                    flag[i]=0;
                }
            }
            for(int i=1; i<=n; i++)
            {
                if(V[i].size()>1)
                {
                    for(int a=1; a<=n; a++)
                        for(int b=1; b<=n; b++)
                            C[a][b]=0;
                    int len=V[i].size();
                    for(int a=0; a<len; a++)
                        for(int b=a+1; b<len; b++)
                        {
                            int a1=V[i][a];
                            int b1=V[i][b];
                            C[a][b]=(C[b][a]-=G[a1][b1]);
                            C[a][a]+=G[a1][b1];
                            C[b][b]+=G[a1][b1];
                        }
                    long long ret=(long long)det(C,len);
                    ans=(ans*ret)%mod;
                    for(int a=0; a<len; a++)
                        f[V[i][a]]=i;
                }
            }
            for(int i=1; i<=n; i++)
            {
                U[i]=f[i]=find(i,f);
                V[i].clear();
            }
            if(k==m)
                break;
            E=e[k].c;
        }

        int a=e[k].a;
        int b=e[k].b;
        int a1=find(a,f);
        int b1=find(b,f);
        if(a1==b1)
            continue;
        flag[a1]=flag[b1]=1;
        U[find(a1,U)]=find(b1,U);
        G[a1][b1]++;
        G[b1][a1]++;
    }

    int co=0;
    for(int i=2; i<=n&&!co; i++)
        if(U[i]!=U[i-1])
            co=1;
    if(m==0)
        co=1;
    if(co) cout<<0<<endl;
    else cout<<ans%mod<<endl;
    }
    return 0;
}
