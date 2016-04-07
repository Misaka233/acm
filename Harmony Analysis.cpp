#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    n=1<<n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            putchar(__builtin_parity(i&j)?'+':'*');
        cout<<endl;
    }

    return 0;
}
