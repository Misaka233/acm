#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{

    int n,m,ans;
    while(scanf("%d",&n)&&n)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            ans^=m;
        }
        if(ans==0) cout<<"Grass Win!"<<endl;
        else cout<<"Rabbit Win!"<<endl;
    }
    return 0;
}
