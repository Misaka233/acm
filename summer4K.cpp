#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char a[300][300];
char str[]={"BJHYN"};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int m,n;
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int co,s=0;
        for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
        {
            for(int k=0;k<5;k++)
            {
                co=0;
                for(int l=0;l<n;l++)
                {if(a[i][l]==str[k]&&a[j][l]==str[k])
                    co+=1;
                }
                s+=co*(co-1)/2;
            }
        }
        cout<<s<<endl;
    }
}
