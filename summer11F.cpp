#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int L=20005;
long long a[L],b[L],c[L];
int main()
{
    int i,j,n;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<n; i++)
           cin>>a[i]>>b[i]>>c[i];
        long long ans = 0,co = 0;
        for(i = 0; i<n; i++)
            for(j = a[i]; j<=b[i]; j+=c[i])
                ans^=j;
        if(ans)
        {
            for(i = 0; i<n; i++)
                for(j = a[i]; j<=b[i]; j+=c[i])
                    if(ans == j) co++;
        cout<<ans<<" "<<co<<endl;
        }
        else
        cout<<"DC Qiang is unhappy."<<endl;
    }
    return 0;
}

