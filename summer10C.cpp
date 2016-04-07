#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>


using namespace std;

const int MAXN = 10010;
const int MAX_N=500005;
int n,m,p,t;
int F[MAXN];
int num[MAXN];
int a[MAX_N];
int b[MAX_N];
long long sum[MAX_N];
struct misaka{
    int u,v,w;
}e[MAX_N];
int find(int x)
{
    if(F[x]==-1) return x;
    else return F[x]=find(F[x]);
}
void unite(int x,int y)
{
    int f1=find(x);
    int f2=find(y);
    if(f1!=f2)
    {
        F[f1]=f2;
        num[f2]+=num[f1];
    }

}
bool cmp(misaka a,misaka b)
{
    return a.w<b.w;
}
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            F[i]=-1;
            num[i]=1;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e+m,cmp);
        for(int i=0;i<m;i++)
        {
            b[i]=e[i].w;
        }
        for(int i = 0;i < m;i++)
        {
            if(find(e[i].u) != find(e[i].v))
            {
                a[i] = 2*num[find(e[i].u)]*num[find(e[i].v)];
                unite(e[i].u,e[i].v);
            }
            else a[i] = 0;
        }
        sum[m]=0;
        for(int i=m-1;i>=0;i--)
        {
            sum[i]=sum[i+1]+a[i];
        }
        scanf("%d",&p);
        while(p--)
        {
            scanf("%d",&t);
            int id=lower_bound(b,b+m,t)-b;
            if(id>=m) cout<<0<<endl;
            else{
                cout<<sum[id]<<endl;
            }
        }
    }
    return 0;
}
