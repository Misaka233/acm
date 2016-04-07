#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct misaka
{
    int num;
    int size;
}node[100010];
int a[100010];
misaka q[100010];
int main()
{
    int n,co=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    node[1].num=a[1];
    node[1].size=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            node[co].size++;
        }
        else
        {
            co++;
            node[co].num=a[i];
            node[co].size=1;
        }
    }
    //for(int i=1;i<=co;i++)
    //{
      //  cout<<node[i].num<<" "<<node[i].size<<endl;
   // }
    q[1]=node[1];
    q[2]=node[2];
    int ans=node[1].size+node[2].size;
    int co2=node[1].size+node[2].size;
    for(int i=3;i<=co;i++)
    {
        if(node[i].num-node[i-1].num<=1&&node[i].num-node[i-1].num>=-1&&node[i].num-node[i-2].num<=1&&node[i].num-node[i-2].num>=-1)
        {
            q[1]=q[2];
            q[2]=node[co];
            co2+=node[i].size;
        }
        else
        {
            q[1]=q[2];
            q[2]=node[co];
            co2=node[i].size+node[i-1].size;
        }
        ans=max(ans,co2);
    }
    printf("%d",ans);
    return 0;
}
