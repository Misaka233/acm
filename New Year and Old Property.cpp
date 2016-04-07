#include<bits/stdc++.h>
using namespace std;
long long a[5000];

int main()
{
    long long x,y;
    cin>>x>>y;
    long long co=0;
    for(long long i=2;i<=61;i++)
    {
        for(long long j=i-2;j>=0;j--)
        {
            a[co++]=(((long long)1<<i)-1)-(((long long)1<<j));
        }
    }
    long long xx,yy;
    long long flagx=0,flagy=0;
    //for(int i=0;i<=co/2;i++)
      //  cout<<a[i]<<" ";
    for(int i=0;i<=co;i++)
    {
        if(a[i]>=x)
        {
            xx=i;
            if(a[i]==x) flagx=1;
            break;
        }
    }
    for(int i=0;i<=co;i++)
    {
        if(a[i]>=y)
        {
            yy=i;
            if(a[i]==y) flagy=1;
            break;
        }
    }
    long long ans=yy-xx;
    if(x==y) ans+=flagx;
    else if(flagy==1&&flagx!=1) ans++;
    else if(flagy==1&&flagx==1) ans++;
    //else ans+=flagx+flagy;
    cout<<ans<<endl;
    return 0;
}
