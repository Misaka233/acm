#include<bits/stdc++.h>
using namespace std;
long long num[1000010];
string s;
int main()
{
    int k,co=0;
    long long ans=0;
    cin>>k;
    cin>>s;
    num[0]=1;
    int length=s.size();
    for(int i=0;i<length;i++)
    {
        if(s[i]=='1') co++;
        if(co>=k) {ans+=num[co-k];}//到第i位，第 co-k 个1前面有几个0答案就有几种可能
        num[co]++;//第co-1个1前面0个数
    }
    cout<<ans<<endl;
    return 0;
}
