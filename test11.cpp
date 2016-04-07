#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct node
{
    int x,y,z;
    int step;
};

int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int mx[4]={1,0,-1,0};
int my[4]={0,1,0,-1};
node s_pos;

char map[2][15][15];
int N,M,T;

bool visited[2][15][15];

int flag;
int cheak(int x,int y,int z)
{
    if(x>=0&&x<=1&&y>=0&&y<N&&z>=0&&z<M&&map[x][y][z]!='*')
        return 1;
    return 0;
}
void BFS()
{
    int i;

    memset(visited,0,sizeof(visited));

    visited[s_pos.x][s_pos.y][s_pos.z]=1;

    queue<node>Q;

    Q.push(s_pos);

    while(!Q.empty())
    {
        node temp=Q.front();
        Q.pop();
        if(map[temp.x][temp.y][temp.z]=='P'&&temp.step<=T)
        {
            flag=1;
            cout<<temp.step;
            return ;
        }
        for(i=0;i<4;i++)
        {
            node p;
            p=temp;
            p.y+=mx[i];
            p.z+=my[i];
            p.step+=1;

            if(cheak(p.x,p.y,p.z)&&!visited[p.x][p.y][p.z]&&p.step<=T)
            {
                visited[p.x][p.y][p.z]=1;
                if(map[p.x][p.y][p.z]=='#')
                {
                    if(map[(p.x+1)%2][p.y][p.z]!='*'&&!visited[(p.x+1)%2][p.y][p.z])
                        p.x=(p.x+1)%2;
                }

                Q.push(p);

            }

        }

    }

}
int main()
{
    int t;
    int k,i,j;
    cin>>t;
    while(t--)
    {
        cin>>N>>M>>T;
        for(k=0;k<=1;k++)
            for(i=0;i<N;i++)
                for(j=0;j<M;j++)
                {
                    cin>>map[k][i][j];
                    if(map[k][i][j]=='S')
                    {
                        s_pos.x=k,s_pos.y=i,s_pos.z=j;
                        s_pos.step=0;
                    }
                }

                for(i=0;i<N;i++)
                {
                    for(j=0;j<M;j++)
                    {
                        if(map[0][i][j]=='#'&&map[1][i][j]=='*')
                        {
                            map[0][i][j]=map[1][i][j]='*';
                        }

                        if(map[0][i][j]=='*'&&map[1][i][j]=='#')
                        {
                            map[0][i][j]=map[1][i][j]='*';
                        }

                        if(map[0][i][j]=='#'&&map[1][i][j]=='#')
                        {
                            map[0][i][j]=map[1][i][j]='*';
                        }

                    }
                }


                flag=0;
                BFS();
                if(!flag)
                    cout<<"NO"<<endl;
                else
                    cout<<"YES"<<endl;


    }
    return 0;
}
