#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct misaka{
    int a,b;
}a[100007];
int t[100010],n;
long long int ans;
bool cmp(misaka a,misaka b)
{
    if(a.a<b.a) return true;
    else if(a.a==b.a&&a.b<b.b) return true;
    else return false;
}
void guibin(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    guibin(l,mid);
    guibin(mid+1,r);
    int i=l,j=mid+1,k=l,p;
    while(i<=mid&&j<=r)
    {
        if(a[i].b>a[j].b)
        {
            ans+=mid-i+1;
            t[k]=a[j].b;
            j++;
        }
        else
            {
                t[k]=a[i].b;
                i++;
            }
            k++;
    }
    if(i==mid+1)
    {
        for(p=j;p<=r;p++) t[k++]=a[p].b;
    }
    else
    {
        for (p=i;p<=mid;p++) t[k++] = a[p].b;
    }
    for (k=l;k<=r;k++) a[k].b = t[k];
}
int main()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].a,&a[i].b);
    sort(a+1,a+1+n,cmp);
    guibin(1,n);
    printf("%lld\n",ans);
    return 0;
}
