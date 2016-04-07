#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200010;
const int INF=2333333;
int Min,Max;
int a[maxn];
struct misaka
{
    int l,r;
    int Min,Max;
}seg[3*maxn];
void build(int i,int l,int r)
{
    seg[i].l=l;
    seg[i].r=r;
    if(l==r)
    {
        seg[i].Min=seg[i].Max=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    seg[i].Max=max(seg[i*2].Max,seg[i*2+1].Max);
    seg[i].Min=min(seg[i*2].Min,seg[i*2+1].Min);
}
void query(int i,int l,int r)
{
    if(seg[i].Max<=Max&&seg[i].Min>=Min) return ;
    if(seg[i].l==l&&seg[i].r==r)
    {
        Max=max(seg[i].Max,Max);
        Min=min(seg[i].Min,Min);
        return ;
    }
    int mid=(seg[i].l+seg[i].r)/2;
    if(r<=mid) query(i<<1,l,r);
    else if(l>mid) query(i<<1|1,l,r);
    else
    {
       query(i<<1,l,mid);
       query(i<<1|1,mid+1,r);
    }
}
int main()
{
    int N,Q,l,r,i;
    while(~scanf("%d%d",&N,&Q))
    {
        for(i=1;i<=N;i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,1,N);
        for(i=1;i<=Q;i++)
        {
            scanf("%d%d",&l,&r);
            Max=-INF;
            Min=INF;
            query(1,l,r);
           //cout<<Max<<Min;
          /* for(int j=1;j<=N*2-1;j++)
           {
               cout<<seg[j].Max<<" "<<seg[i].Min<<endl;
           }*/
            printf("%d\n",Max-Min);
        }
    }
    return 0;
}
