#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
const int maxe=25007;
int visit[maxn];
struct misaka
{
    int first;
    int secend;
}E[maxe];
bool cmp(misaka a,misaka b)
{
    return a.first<b.first;
}
int main()
{
    int n,e;
    while(scanf("%d%d",&n,&e)&&n!=0&&e!=0)
    {
        memset(visit,0,sizeof(visit));
        for(int i=0;i<e;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u>v)
            {
                swap(u,v);
            }
            E[i].first=u;
            E[i].secend=v;
        }
        sort(E,E+e,cmp);
        for(int i=e;i>=0;i--)
        {
            if(visit[E[i].first]!=1&&visit[E[i].secend]!=1)
            {
                visit[E[i].first]=1;
                visit[E[i].secend]=2;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visit[i]==1) printf("1");
            else printf("0");
        }
    }
    return 0;
}
