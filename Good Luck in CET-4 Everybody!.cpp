#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n%3==0) cout<<"Cici"<<endl;
        else cout<<"Kiki"<<endl;
    }
    return 0;
}
