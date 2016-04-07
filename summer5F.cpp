#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string k;
int main()
{
    double a;
    int n,c;
    int r,b,m=0;
    double f;
    cin>>n>>c;
    r=0;b=0;f=0;
    while(n--)
    {
        cin>>a;
        cin>>k;
        r+=a;
        if(k[0]=='b'&&k[1]=='e'&&k[2]=='d') b+=a;
        if(k[0]=='b'&&k[1]=='a'&&k[2]=='l')
        {
            f+=a/2.0;
            m+=a;
        }
        else
            f+=a;
    }
    double res=f*c;
    printf("%d\n%d\n",r,b);
    if(m%2==0||(m%2==1&&c%2==0)) printf("%.0lf\n",res);
    else printf("%.1lf\n",res);
    return 0;
}
