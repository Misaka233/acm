#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct misaka{
int a;
int b;
}l[5005];
int col[5005];
bool cmd(misaka x,misaka y)
{
  return x.b>y.b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(l,0,sizeof(l));
        memset(col,0,sizeof(col));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>l[i].a>>l[i].b;
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        //sort(l,l+n,cmd);
        int co=n-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(l[i].b<=l[j].b&&l[i].a<=l[j].a)
                    col[j]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(col[i]>0) ans++;
        }
        cout<<ans<<endl;
    }
}
