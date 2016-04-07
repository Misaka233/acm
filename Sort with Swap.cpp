#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000+10;
int a[maxn];
bool flag[maxn];
int f(int x)
{
    int r=0;
    bool have=false;
    for( ;!flag[x];r++)
    {
        if(x==0)
        {
            have=true;
        }
        flag[x]=true;
        x=a[x];
    }
    return have?(r-1):((r<=1)?0:(r+1));
}
int main()
{
    memset(flag,false,sizeof(flag));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=f(a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
