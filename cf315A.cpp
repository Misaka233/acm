#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;
int t,s,p;
int main()
{
    scanf("%d %d %d",&t,&s,&p);
    int l=t;
    int x1=0,x2=s;
    int co=1;
    while(x1<l)
    {
        x1=x1+p;
        x2=x2+p-1;
        if(x1>=l&&x2>=l) break;
        if(x1>=x2)
        {
            x1=0;
            co++;
        }
    }
    cout<<co<<endl;
    return 0;
}
