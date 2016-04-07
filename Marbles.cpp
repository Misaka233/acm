#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n1,n2,n,c1,c2;
ll extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main()
{
    while(cin>>n&&n)
    {
        cin>>c1>>n1>>c2>>n2;
        ll x,y;
        ll g=extend_gcd(n1,n2,x,y);
        ll lower = ceil(-1.0 * n * x /n2);
        ll up = floor(1.0 * n * y /n1);
        if (lower > up || n %g!=0)
        {
            printf("failed\n");
            continue;
        }
        if(c1 * n2 <= c2 * n1)
        {
            x = n2/g *up + n/g* x;
            y = n/g*y - n1/g*up;
        }
        else
        {
            x = n2/g*lower + n/g*x;
            y = n/g*y-n1/g*lower;
        }
        cout<<x<<" "<<y<< endl;
    }

    return 0;
}
