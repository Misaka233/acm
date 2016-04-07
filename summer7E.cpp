#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[10];
int main()
{
    int t,cas;
    cin>>t;
    string s;
   getline(cin,s);
    for(cas=1;cas<=t;cas++)
    {
        getline(cin,s);
        memset(a,0,sizeof(a));

        int ans=2000;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='g') a[0]++;
            if(s[i]=='o') a[1]++;
            if(s[i]=='d') a[2]++;
            if(s[i]=='m') a[3]++;
            if(s[i]=='r') a[4]++;
            if(s[i]=='n') a[5]++;
            if(s[i]=='i') a[6]++;
            if(s[i]==' ') a[7]++;
        }
        //if(a[0]>0) a[0]--;
        a[1]/=3;
        a[5]/=2;
        for(int i=0;i<=7;i++)
        {
            if(a[i]<ans) ans=a[i];
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
