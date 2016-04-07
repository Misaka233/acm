#include<iostream>
#include<cstdio>
using namespace std;
int a[15],co;
void f(int n)
{
    co=0;
    while(n)
    {
        a[co++]=n%10;
        n/=10;
    }
    for(int i=0;i<co;i++)
    {
        if(a[i]>8) a[i]-=2;
        else if(a[i]>3) a[i]-=1;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        f(n);
        int res=0;
        for(int i=co-1;i>=0;i--)
        {
            res*=8;
            res+=a[i];
        }
        cout<<n<<": "<<res<<endl;
    }
    return 0;
}
