#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=10010;
vector<int>map[maxn];
bool vis[maxn];
bool light[maxn];
int ans;
void misaka(int id,int from)
{
    vis[id]=1;
    bool flag=false;
    for(int i=0;i<map[id].size();i++)
    {
        if(vis[map[id][i]]==false)
        {
            misaka(map[id][i],id);
            flag=flag||light[map[id][i]];
        }
    }
    if(from==-1) ans+=!(light[id]||flag);
    else if(!light[from]&&!light[id]&&!flag)
    {
        light[from]=true;
        ans++;
    }
}
int main()
{
    int n,v,u;
    memset(vis,0,sizeof(vis));
    memset(light,0,sizeof(light));
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u,&v);
        map[u].push_back(v);
        map[v].push_back(u);
    }
    ans=0;
    misaka(1,-1);
    printf("%d\n",ans);
    return 0;
}
