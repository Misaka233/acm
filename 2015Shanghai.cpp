#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
#include<time.h>
using namespace std;
const int INF=1<<30;
typedef long long ll;

ll a[200000],b[200000],v[500000],c[200000],T[200000],mark[200000],biao[200000];
ll cnt1,cnt2,n,mod;

void build(int l,int r,int k){
    if(l==r){
        v[k]=a[l];
        mark[l]=k;
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,k*2+1);
    build(mid+1,r,k*2+2);
    v[k]=(v[k*2+1]*v[k*2+2])%mod;
}

ll query(int l,int r,int L,int R,int k){
    if(l==L&&r==R){
        return v[k];
    }
    int mid=(L+R)/2;
    if(r<=mid){
        return query(l,r,L,mid,k*2+1);
    }
    else if(l>mid){
        return query(l,r,mid+1,R,k*2+2);
    }
    else{
        return (query(l,mid,L,mid,k*2+1)*query(mid+1,r,mid+1,R,k*2+2))%mod;
    }
}

void update(int k){
    v[k]=1;
    while(k){
        k=(k-1)/2;
        v[k]=(v[k*2+1]*v[k*2+2])%mod;
    }
}

int main()
{
    int i,j,t,ct=0;cin>>t;
    while(t--){
        ct++;
        scanf("%I64d%I64d",&n,&mod);
        fill(v,v+200000,1);
        printf("Case #%d:\n",ct);
        cnt1=0,cnt2=0;
        int last=0;
        for(i=0;i<n;i++){
            ll w;
            scanf("%I64d%I64d",&T[i],&w);
            if(T[i]==1){
                a[cnt1]=w;
                biao[i]=cnt1;
                last=cnt1++;
            }
            else{
                b[cnt2]=biao[w-1];
                c[cnt2++]=last;
            }
        }
        build(0,cnt1,0);
        ll q=0,w=0;
        for(i=0;i<n;i++)
            {
            if(T[i]==1){
                printf("%I64d\n",query(0,q,0,cnt1,0)%mod);
                q++;
            }
            else{
                ll an=b[w];
                update(mark[an]);

                printf("%I64d\n",query(0,c[w],0,cnt1,0)%mod);
                w++;
            }
        }
    }
    return 0;
}
