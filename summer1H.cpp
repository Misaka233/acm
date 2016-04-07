#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=10050;
int a[maxn];
double b[188];
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        memset(b,0,sizeof(b));
        int n,ans,ans1,ans2,ans3;
        ans=99999999;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]]++;
        }
        for(int i=0;i<160;i++)
        {
            b[i]+=b[i-1];
        }

        double p=n/4.0;
        for(int i=0;i<160;i++)
        {
            for(int j=i+1;j<160;j++)
            {
                for(int k=j+1;k<160;k++)
                {
                    if(abs(b[i]-p)+abs(b[j]-b[i]-p)+abs(b[k]-b[j]-p)+abs(n-b[k]-p)<ans)
                    {
                        ans=abs(b[i]-p)+abs(b[j]-b[i]-p)+abs(b[k]-b[j]-p)+abs(n-b[k]-p);
                        ans1=i;ans2=j;ans3=k;
                    }
                }
            }
        }
        cout<<"Case "<<cas<<": "<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
    return 0;
}
