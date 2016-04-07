#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
struct misaka
{
    string name;
    int id;
    int num;
    bool jin;
    int shun;
}a[150010];
bool cmp(misaka a,misaka b)
{
    if(a.num<b.num) return true;
    else if(a.id<b.id) return true;
    return false;
}
vector<string>jilu;
using namespace std;
int main()
{
    int T,t,k,m,q,p;
    string jilu[150010];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&k,&m,&q);
        for(int i=0;i<k;i++)
        {
            cin>>a[i].name;
            scanf("%d",&a[i].num);
            a[i].id=i;
            a[i].jin=0;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&t,&p);
            int co=0,ss=0;
            while(co<t)
            {
                for(int j=0;j<t;j++)
                {
                    if(a[j].jin==0)
                    {
                        a[j].jin=1;
                        a[j].shun=ss;.
                        ss++;
                    }
                }
            }
        }
    }
    return 0;
}
