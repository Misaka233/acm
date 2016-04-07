#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define MAXN 505
#define RST(N)memset(N, 0, sizeof(N))
using namespace std;

int n, m, u, v,k;
bool first;
int graph[MAXN][MAXN],pur[MAXN],degree[MAXN];  //图的邻接矩阵，每个顶点的入度；
priority_queue <int, vector<int>, greater<int> > q;   //优先队列；

void Init()
{
    RST(graph), RST(degree);
    memset(pur,-1,sizeof(pur));
    while(!q.empty()) q.pop();
    for(int i=0; i<m; i++) {
        scanf("%d %d", &u, &v);
        u++;v++;
        if(!graph[u][v]) {
            graph[u][v] = 1;
            degree[v]++;
        }
    }
    first = 1;
    for(int i=1; i<=n; i++) if(!degree[i]) q.push(i);
}

int main()
{
    while(~scanf("%d %d %d", &n, &m,&k)) {
        Init();
        int kk=0;
        while(!q.empty()) {
            int current = q.top();
            q.pop();
            pur[kk++]=current-1;
            if(kk==k)break;//printf(" %d", current);
            for(int i=1; i<=n; i++)
                {
                    if(graph[current][i])
                {
                    degree[i]--;
                    if(degree[i] == 0) q.push(i);
                }
            }
        }
        int ans=0;
        //cout<<ans<<"  ";
        if(kk<k) cout<<-1<<endl;
        else{
          for(int i=0;i<kk-1;i++)
               {cout<<pur[i]<<" ";}
           cout<<pur[kk-1]<<endl;
          }
    }
    return 0;
}
