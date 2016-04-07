#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    char a;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,co=0;
        cin>>n>>m;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                cin>>a;
                if(a=='O') co++;
            }
        }
        if(co%2==1) cout<<"Case "<<i<<": Maze"<<endl;
        else cout<<"Case "<<i<<": Fat brother"<<endl;
    }
    return 0;
}
