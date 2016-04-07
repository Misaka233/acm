#include<cstdio>
#include<cstring>
#define INF 0x1f1f1f1f
#define clr(x)memset(x,0,sizeof(x))
#define min(a,b)(a)<(b)?(a):(b)
#define maxn 555
int g[maxn][maxn];
int cb[maxn];
int minc,n,m;
void find(int &s,int &t)
{
    int v[maxn];
    int w[maxn];
    clr(v);  clr(w);
    int tmpj=INF,tmax,i,j;
    for(i=0;i<n;i++)
    {
        tmax=-INF;
        for(j=0;j<n;j++)
            if(!v[j]&&!cb[j]&&tmax<w[j])
            {
                tmax=w[j];
                tmpj=j;
            }
        if(t==tmpj)
        {
            minc=w[t];
            return;
        }
        v[tmpj]=1;
        s=t;
        t=tmpj;
        for(j=0;j<n;j++)
            if(!v[j]&&!cb[j])
                w[j]+=g[t][j];
    }
    minc=w[t];
}
int min_cut()
{
    int res=INF;
    int i,j,s,t;
    clr(cb);
    minc=INF;
    for(i=0;i<n-1;i++)
    {
        s=t=-1;
        find(s,t);
        cb[t]=1;
        res=min(res,minc);
        for(j=0;j<n;j++)
        {
            g[s][j]+=g[t][j];
            g[j][s]+=g[j][t];
        }
    }
    return res;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        clr(g);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]+=c;
            g[b][a]+=c;
        }
        printf("%d\n",min_cut());
    }
    return 0;
}
