#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxx=200010;
int w,h,k;
int a[200010];


struct node
{
 int r,l,key;
}no[maxx*4];

void build(int l,int r,int root)
{

 no[root].l=l;
 no[root].r=r;
 no[root].key=w;

 if(l!=r)
 {
  int mid=(l+r)/2;
  build(l,mid,root*2);
  build(mid+1,r,root*2+1);
 }
}

void query(int q,int root)
{
    if(no[root].l==no[root].r)
        k=no[root].l;
    else
    {
        if(no[root*2].key>=q)
            query(q,root*2);
        else if(no[root*2+1].key>=q)
            query(q,root*2+1);
        else
            k=-1;
    }
}

void updata(int w,int root)
{
 if(no[root].r==no[root].l)
     no[root].key-=w;
 else
 {
  if(no[root*2].key>=w)
   updata(w,root*2);
  else
   updata(w,root*2+1);

  no[root].key=max(no[root*2].key,no[root*2+1].key);
 }
}

int main()
{
 int n;
 while(scanf("%d%d%d",&h,&w,&n)!=EOF)
 {
     if(h>n)h=n;
    build(1,h,1);
    for(int i=0;i<n;i++)
    {
        k=0;
        scanf("%d",&a[i]);
        query(a[i],1);
        printf("%d\n",k);
        if(k>=0)
            updata(a[i],1);
    }
 }
}
