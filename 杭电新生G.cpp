#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
ll f[55];
int father[1010];
int v[1010];
int b[1010];
int getf(int v)
{
    if (father[v]==v)
    {
        return v;
    }
    else
    {
        father[v]=getf(father[v]);
        return father[v];
    }
}
void init()
{
    f[1]=0;
    f[2]=1;
    for (int i=3; i<=48; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
}
int main()
{

    init();
    int m,n;
    while(cin>>n>>m)
        {
        for (int i=1; i<=1000; i++)
        {
            father[i]=i;
            b[i]=0;
        }
        for (int i=1; i<=n; i++)
        {
            cin>>v[i];
            int k=lower_bound(f, f+48, v[i])-f;
            if (v[i]==f[k])
            {
                b[i]=1;
            }
        }
        for (int i=1; i<=m; i++)
        {
            int q,p;
            cin>>q>>p;
            int fq=getf(q);
            int fp=getf(p);
            if(fq!=fp){
                b[fq]+=b[fp];
                father[fp]=fq;
            }
        }
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            ans=max(ans,b[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
