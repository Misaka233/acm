#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
long long a[maxn];
int main()
{
    long long n;
    long long flag=1000000001;
    cin>>n;
    long long kk=0;
    long long re=0;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);

        //flag=min(flag,a[i]);
    }
    for(int i=0;i<=(n-1);i++)
    {

        if(flag>=a[i])
        {
            flag=a[i];
            kk=0;
        }
        else
        {
            kk++;
            re=max(re,kk);
        }
    }
    for(int i=0;i<=(n-1);i++)
    {

        if(flag>=a[i])
        {
            flag=a[i];
            kk=0;
        }
        else
        {
            kk++;
            re=max(re,kk);
        }
    }
    long long ans=flag*n;
    cout<<ans+re<<endl;
    return 0;
}
