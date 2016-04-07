#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
#include<algorithm>
const int M=100005;
using namespace std;
struct edge {
    long long from,to,c;
} e[M];
struct node {
    long long time;
    long long v;
    node(long long _v, long long _time):v(_v), time(_time) {}
    friend bool operator < (node A,node B) {
        return A.time > B.time;
    }
};
int n;
long long m;
bool cmp(edge A, edge B) {
    return A.from < B.from;
}
long long bfs() {
    priority_queue<node>q;
    q.push(node(1,0));
    int left = 0, i;
    while(!q.empty()) {
        node pre = q.top();
        q.pop();
        if(pre.v >= m) return pre.time;
        for(i=left; i<n; ++i) {
            if(pre.v < e[i].to && pre.v >= e[i].from)
                q.push(node(e[i].to,pre.time+e[i].c));
            if(e[i].from > pre.v) break;
        }
        left = i;
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    for(int kase = 1; kase <= t; ++kase) {
        printf("Case #%d: ",kase);
        scanf("%d%lld",&n,&m);
        for(int i=0; i<n; ++i)
            scanf("%lld%lld%lld",&e[i].to,&e[i].from,&e[i].c);
        sort(e,e+n,cmp);
        printf("%lld\n",bfs());
    }
    return 0;
}
