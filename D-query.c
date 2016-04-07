#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=100001;
struct Node{
    int ls,rs;
    int cnt;
}tr[maxn*20];
int cur,rt[maxn];
void init(){
    cur=0;
}
inline void push_up(int o){
    tr[o].cnt=tr[tr[o].ls].cnt+tr[tr[o].rs].cnt;
}
int build(int l,int r){
    int k=cur++;
    if (l==r) {
        tr[k].cnt=0;
        return k;
    }
    int mid=(l+r)>>1;
    tr[k].ls=build(l,mid);
    tr[k].rs=build(mid+1,r);
    push_up(k);
    return k;
}
int update(int o,int l,int r,int pos,int val){
    int k=cur++;
    tr[k]=tr[o];
    if (l==pos&&r==pos){
        tr[k].cnt+=val;
        return k;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) tr[k].ls=update(tr[o].ls,l,mid,pos,val);
    else tr[k].rs=update(tr[o].rs,mid+1,r,pos,val);
    push_up(k);
    return k;
}
int query(int l,int r,int o,int pos){
    if (l==r) return tr[o].cnt;
    int mid=(l+r)>>1;
    if (pos<=mid) return tr[tr[o].rs].cnt+query(l,mid,tr[o].ls,pos);
    else return query(mid+1,r,tr[o].rs,pos);
}
int b[maxn];
map<int,int> mp;
int main()
{
    int n,m;
    //int T;
    //scanf("%d",&T);
    //while (T--){
    while (~scanf("%d",&n)){
        mp.clear();
        init();
        for (int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        rt[0]=build(1,n);
        for (int i=1;i<=n;i++){
            if (mp.find(b[i])==mp.end()){
                mp[b[i]]=i;
                rt[i]=update(rt[i-1],1,n,i,1);
            }
            else{
                int tmp=update(rt[i-1],1,n,mp[b[i]],-1);
                rt[i]=update(tmp,1,n,i,1);
            }
            mp[b[i]]=i;
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int ans=query(1,n,rt[b],a);
            printf("%d\n",ans);
        }
    }
    return 0;
}

SPOJ 3267 D-query
