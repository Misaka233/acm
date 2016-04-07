#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[1000];

int f(int n)
{
    if(n%7==0) return 1;
    while(n)
    {
        if(n%10==7) return 1;
        else n/=10;
    }
    return 0;
}
int main()
{
    memset(a,0,sizeof(a));

    for(int i=1;i<1000;i++)
    {
        if(f(i)) a[i]++;
    }
    int t;
    cin>>t;

    while(t--)
    {
        int p,i;
        cin>>p;
        if(p==1)
        {
            cout<<7<<endl;
            continue;
        }
        int co=1;
        for(i=1;i<1000;i++)
        {
            if(a[i-1]&&a[i])
            {
                co+=1;
                if(co==p) break;
            }
            else co=1;

        }
        cout<<i-p+1<<endl;
    }
    return 0;
}
