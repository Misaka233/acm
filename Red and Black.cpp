#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
char map[50][50];
int n,m,co;
void dfs(int mi,int mj)
{
    if(0<=mi&&mi<m&&mj>=0&&mj<n&&map[mi][mj]=='.')
    {
        co++;
        map[mi][mj]='#';
    }
    else
    {
        return ;
    }
    dfs(mi-1,mj);
    dfs(mi,mj-1);
    dfs(mi,mj+1);
    dfs(mi+1,mj);

}
int main()
{
    while(scanf("%d%d",&n,&m)&&m!=0&&n!=0)
    {
        co=0;
        int mi,mj;
        memset(map,0,sizeof(map));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='@')
                {
                    mi=i;
                    mj=j;
                    map[i][j]='.';
                }
            }
        }
        dfs(mi,mj);
        cout<<co<<endl;
    }

    return 0;
}
