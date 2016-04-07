#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
long long A1[233333],A2[233333];
long long value[233333],point[233333];
long long T[233333],mark[233333],b[233333];
long long C1,C2,n,mod;

void build(int L,int R,int k)
{
    if(L==R)
    {
        mark[L]=k;
        value[k]=A1[L];
        return ;
    }
    int m=(L+R)>>1;
    build(L,m,k*2+1);
    build(m+1,R,k*2+2);
    value[k]=(value[k<<1+1]*value[k<<1+2])%mod;
}

long long check(int l,int r,int L,int R,int k){
    if(l==L&&r==R){
        return value[k];
    }
    int m=(L+R)/2;
    if(r<=m){
        return check(l,r,L,m,k*2+1);
    }
    else if(l>m){
        return check(l,r,m+1,R,k*2+2);
    }
    else{
        return (check(l,m,L,m,k*2+1)*check(m+1,r,m+1,R,k*2+2))%mod;
    }
}

void Update(int k){
    value[k]=1;
    while(k!=0){
        k=(k-1)>>1;
        value[k]=(value[k<<1+1]*value[k<<1+2])%mod;
    }
}

int main()
{
    int i,j,t,Q=0;cin>>t;
    while(t--){
        cin>>n>>mod;
        printf("Case #%d:\n",++Q);
        fill(value,value+233333,1);
        C1=0,C2=0;
        int last=0;
        for(i=0;i<n;i++){
            long long va;
            cin>>T[i]>>va;
            if(T[i]==1){
                A1[C1]=va;
                b[i]=C1;
                last=C1++;
            }
            else if(T[i]==2){
                A2[C2]=b[va-1];
                point[C2++]=last;
            }
        }
        build(0,C1,0);
        int q=0,w=0;
        for(i=0;i<n;i++){
            if(T[i]==1){
                cout<<check(0,q,0,C1,0)%mod<<endl;
                q++;
            }
            else{
                long long id=A2[w];
                Update(mark[id]);
                cout<<check(0,point[w],0,C1,0)%mod<<endl;
                w++;
            }

        }
    }
    return 0;
}
