#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"10"<<endl;
        return 0;
    }
    else if(n==2)
    {
        cout<<"60 80"<<endl;
        return 0;
    }
    else if(n==3)
    {
        cout<<"01 60 80"<<endl;
        return 0;
    }
    else if(n==4)
    {
        cout<<"11 01 60 80"<<endl;
        return 0;

    }
    else
    {
        cout<<"Glupenky Pierre"<<endl;
        return 0;
    }
}
