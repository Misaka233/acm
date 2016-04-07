#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    long long l,r,k;
    cin>>l>>r>>k;
    int flag=0;
    long long ans=1;
    for(int i=0;i<64;i++)
    {
        ans*=i;
        if(ans>=l&&ans<=r)
        {
            cout<<ans<<" ";
            flag=1;
        }
        if(ans>r)
        {
            break;
        }
    }
    if(flag==0)
        cout<<-1;
    return 0;
}
