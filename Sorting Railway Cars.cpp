#include<bits/stdc++.h>
using namespace std;
int a[100007];
int b[100007];
int main()
{
    memset(b,-1,sizeof(b));
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=max(b[a[i]-1],0)+1;
        ans=max(ans,b[a[i]]);
    }
    cout<<n-ans<<endl;
    return 0;
}
