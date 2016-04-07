#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int co=199-n;
    if(co<0)
        co=0;
    cout<<co<<endl;
    return 0;
}
