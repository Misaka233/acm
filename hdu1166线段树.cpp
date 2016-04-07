#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
int a[50010];
struct node{
    int l,r,s;
}b[150001];
void build(int l,int r,int i){
    int mid=(l+r)/2;
    b[i].l=l;
    b[i].r=r;
    if(l==r)
    {
        b[i].s=a[l];
        return ;
    }
    build(l,mid,2*i);
    build(mid+1,r,2*i+1);
    b[i].s=b[2*i].s+b[2*i+1].s;
}
int query(int l,int r,int i){
    int mid;
    if(b[i].l==l&&b[i].r==r) return b[i].s;
    mid=(b[i].l+b[i].r)/2;
    if(r<=mid) return query(l,r,2*i);
    else if(l>mid) return query(l,r,2*i+1);
    else return query(l,mid,2*i)+query(mid+1,r,2*i+1);
}
void add(int id,int num,int i){
    if(b[i].l==b[i].r)
    {
        b[i].s=b[i].s+num;
        return ;
    }
    else{
        b[i].s=b[i].s+num;
        if(id<=b[i*2].r) add(id,num,2*i);
        else add(id,num,2*i+1);
    }
}
int main()
{
    int t,cas,n,id,num;
    char c[10];
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>n;
        for(int i=1;i<n;i++)
            cin>>a[i];
        build(1,n,1);
        cout<<"Case "<<cas<<":"<<endl;
        while(1)
        {
            scanf("%s",c);
            if(c[0]=='E') break;
            cin>>id>>num;
            if(c[0]=='Q')
            {
                 printf("%d\n",query(id,num,1));
            }
            if(c[0]=='A')
            {
                add(id,num,1);
            }
            if(c[0]=='S')
            {
                add(id,-num,1);
            }
        }
    }
    return 0;
}
