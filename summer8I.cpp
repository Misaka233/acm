#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
int n;

const ULL INF = ~0;
ULL a[105];
ULL ans;
void dfs(ULL now, int pos) {
    if(ans == 0) return;
    if(pos >= n) {
        ans = min(ans,now);
        return;
    }
    dfs(now | a[pos+1],pos+1);
    dfs(now | ~a[pos+1],pos+1);
    dfs(now & a[pos+1],pos+1);
    dfs(now & ~a[pos+1],pos+1);
    dfs(now ^ a[pos+1],pos+1);
    dfs(now ^ ~a[pos+1],pos+1);
}
int main() {
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase) {

        scanf("%d",&n);
        for(int i=1; i<=n; ++i)
            scanf("%llu",a+i);
        ans = INF;
        dfs(a[1],1);
        dfs(~a[1],1);
        printf("Case #%d: %llu\n",kase,ans);
    }
    return 0;
}
