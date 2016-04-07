#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long a[200000];
long long m[200000];
int main()
{
    long long int n,k,ans=0;
    cin>>n>>k;
    memset(m,0,sizeof(m));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }

    cout<<ans<<endl;
    return 0;
}
