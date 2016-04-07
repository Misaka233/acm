#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
const int inf=954801354;
int pre[maxn],next[maxn][2],key[maxn];
int root,tot1,num;
void NewNode(int &r,int father,int k)
{
    r=++tot1;
    pre[r]=father;
    next[r][0]=next[r][1]=0;
    key[r]=k;
}
void Init()
{
    root=tot1=0;
    next[root][0]=next[root][1]=pre[root]=key[root]=0;
}

void Rotate(int x,int kind)//Ðý×ª
{
    int y=pre[x];
    next[y][!kind]=next[x][kind];
    pre[next[x][kind]]=y;
    if(pre[y])
        next[pre[y]][next[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    next[x][kind]=y;
    pre[y]=x;
}
void Splay(int r,int goal)
{
    while(pre[r]!=goal)
    {
        if(pre[pre[r]]==goal)
            Rotate(r,next[pre[r]][0]==r);
        else
        {
            int y=pre[r];
            int kind=next[pre[y]][0]==y;
            if(next[y][kind]==r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    if(goal==0)root=r;
}
void Insert(int x)
{
    int r=root;
    if(r==0)
    {
        NewNode(root,0,x);
        return;
    }
    while(next[r][key[r]<x])
    {
        r=next[r][key[r]<x];
    }
    NewNode(next[r][key[r]<x],r,x);
    Splay(next[r][key[r]<x],0);
}


int Max(int x)
{
    while(next[x][1])
    {
        x=next[x][1];
    }
    return x;
}
int Min(int x)
{
    while(next[x][0])
    {
        x=next[x][0];
    }
    return x;
}
int main()
{
    int n;
    scanf("%d",&n);
    int x,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(scanf("%d",&x)==EOF) x=0;
        Insert(x);
        if(i==1)
        {
            ans+=x;
        }
        else
        {
            int t=inf;
            if(next[root][0])
                t=min(t,key[root]-key[Max(next[root][0])]);
            if(next[root][1])
                t=min(t,key[Min(next[root][1])]-key[root]);
            ans+=t;
        }
    }
    printf("%d\n",ans);
    return 0;
}
