#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
char a[105],b[105];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i,co=1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(i=0;i<n;i++)
        {

            if(a[i]=='A'&&b[i]!='U') co=0;
            if(a[i]=='T'&&b[i]!='A') co=0;
            if(a[i]=='C'&&b[i]!='G') co=0;
            if(a[i]=='G'&&b[i]!='C') co=0;
        }
        if(co==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
