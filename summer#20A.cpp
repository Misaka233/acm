#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int MAXN=100005;
long long s[MAXN],p[MAXN];
long long minm[MAXN];
int main(){
    long long  n, m, i, j;
    long long t;
    long long x,ans;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%I64d%I64d",&s[i],&p[i]);
        }
        minm[n-1] = s[n-1] * p[n-1];
        for(i=n-2;i>=0;i--){
            long long tt = s[i] * p[i];
            minm[i] = min(tt,minm[i+1]);
        }
        for(i=0;i<m;i++){
            scanf("%I64d",&x);
            int pp = upper_bound(s,s+n,x)-s-1;
            if(pp==n-1){
                ans = x * p[n-1];
            }
            else
                ans = min(minm[pp+1],x*p[pp]);
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

