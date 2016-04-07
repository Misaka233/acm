#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char a,b;
int f[30];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int r;
        cin>>r;
        for(int i=0;i<30;i++)
        {
            f[i]=i;
        }
        for(int i=0;i<r;i++)
        {
            cin>>a>>b;
            for(int j=0;j<30;j++)
            {
                 if(f[j]==b-'A') f[j]=a-'A';
            }

        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]<'A'||s[i]>'Z') cout<<s[i];
            else printf("%c",f[s[i]-'A']+'A');
        }
        cout<<endl;
    }
    return 0;
}
