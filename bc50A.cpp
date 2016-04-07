#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int a[1005];
int b[10005];
int main()
{
    int ans=-1;
    int n;
    while(~scanf("%d",&n))
    {
        memset(b,0,sizeof(b));
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
        for(int i=0;i<10005;i++)
        {
            if(b[i]>n/2) ans=i;
        }
        if(ans==-1) cout<<"-1";
        else cout<<ans;
        cout<<endl;
    }
    return 0;
}
