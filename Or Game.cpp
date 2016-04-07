#include<bits/stdc++.h>
using namespace std;
int a,b,l,r;
double w(int x)
{
    int s=x/(b*2);
    return double(x)/(s*2);
}
int main()
{
    cin>>a>>b;
    if(a<b)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(a==b)
    {
        cout<<a<<endl;
        return 0;
    }
    l=a-b;
    r=a+b;
    printf("%.15f\n",min(w(l),w(r)));
}

