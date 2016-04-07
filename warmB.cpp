#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=110;
int g[maxn][maxn],colo[maxn],A,B;

void f(int p)
{
    int a=0,b=0;
    colo[p]=1;
    for(int i=1;i<p;i++)
        if(g[i][p]&&colo[i]!=colo[p]) a++;
    colo[p]=2;
    for(int i=1;i<p;i++)
        if(g[i][p]&&colo[i]!=colo[p]) b++;
    if(a>b) colo[p]=1,A++;
    else colo[p]=2,B++;
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(colo,0,sizeof(colo));
        memset(g,0,sizeof(g));
        int u,v;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&v,&u);
            g[u][v]=g[v][u]=1;
        }
        B=A=0;
        for(int i=1;i<=n;i++)
            f(i);
        printf("%d",A);
        for(int i=1;i<=n;i++)
        {
             if(colo[i]==1) printf(" %d",i);
        }

        printf("\n");
        printf("%d",B);
        for(int i=1;i<=n;i++)
        {
            if(colo[i]==2) printf(" %d",i);
        }

        printf("\n");

    }
    return 0;
}
