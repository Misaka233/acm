#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int pos[256];
int len[256];
int main()
{
    int ans=0;
    string s;
    cin>>s;
    for(int i=0;i<256;i++)
    {
        pos[i]=-1;
        len[i]=0;
    }
    len[0]=1;
    for(int i=0;i<s.size();i++)
    {
        if(pos[s[i]-'a']==-1)
        {
            len[i]=len[i-1]+1;
        }
        else
        {
            len[i]=i-pos[s[i]-'a'];
        }
        pos[s[i]-'a']=i;
        ans=max(ans,len[i]);
    }
    cout<<ans;
    return 0;
}
