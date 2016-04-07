#include<bits/stdc++.h>
using namespace std;
struct misaka
{
    int len,num;
}arr[200010];
int T,t,n,m;
int l[200010],r[200010];
int v[200010],ans[200010];
bool cmp(misaka a,misaka b)
{
    return a.num>b.num;
}
int main()
{
    int i,j,k,len;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        l[i]=r[i]=i;
    }
    for(i=1;i<=n;i++)
       while(v[l[i]-1]>=v[i])
         l[i]=l[l[i]-1];
    for(i=n;i>=1;i--)
       while(v[r[i]+1]>=v[i])
         r[i]=r[r[i]+1];
    for(i=1;i<=n;i++)
    {
        arr[i].len=r[i]-l[i]+1;
        arr[i].num=v[i];
    }
    sort(arr+1,arr+1+n,cmp);
    ans[0]=1e9+7;
    for(i=1;i<=n;i++)
    {
        len=arr[i].len;
        while(ans[len]<arr[i].num)
        {
            ans[len]=arr[i].num;
            len--;
        }
    }
    for(i=1;i<=n;i++)
       printf("%d ",ans[i]);
    printf("\n");
}
