#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans,sum,n,a[107];
    while(scanf("%d",&n)&&n)
    {
        sum=0;ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum^=a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]>(sum^a[i])) ans++;
        }
        cout<<ans<<endl;
    }
}
