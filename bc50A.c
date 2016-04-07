#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int a[1005];
int b[1005];
int main()
{
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
        for(int i=0;i<n;i++)
        {
            if(b[i]>=2) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
