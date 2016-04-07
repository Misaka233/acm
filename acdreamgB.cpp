#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int a[1005];
int map[1005][1005];
int k,kk;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(map,0,sizeof(map));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            cin>>k;
            for(int j=0;j<k;j++)
            {
                cin>>kk;
                map[i][kk]=map[kk][i]=1;
            }
        }

            int ans=0,min=INF;
         /*for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(map[i][j]!=0) v[i]+=a[j];
                }
            }*/
        int nn=n-1;
        while(nn--)
        {

            int ii=max_element(a,a+n)-a;

            for(int i=0;i<n;i++)
            {
                if(map[ii][i]!=0) ans+=a[i];
                map[ii][i]=map[i][ii]=0;
            }
             a[ii]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
