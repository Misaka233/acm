
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
struct dice{
    int id;
    int num;
    int a[110];
}die[1050];
bool cmp(dice a,dice b)
{
    return a.num<b.num;
}
bool cmpp(dice a,dice b)
{
    return a.id<b.id;
}
int main()
{
    cin>>n;
    int m=0;
    double ans=0;
    for(int i=1;i<=n;i++)
        {
            cin>>die[i].num;
            die[i].id=i;
            m+=die[i].num;
        }
    sort(die+1,die+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=die[i].num;j++)
        {
            die[i].a[j]=m--;
            ans+=die[i].a[j]*1.0/die[i].num;
        }
    }
    sort(die+1,die+1+n,cmpp);
    printf("%.5lf\n",ans);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=die[i].num;j++)
        {
            printf("%d ",die[i].a[j]);
        }
        printf("\n");
    }
    return 0;
}
