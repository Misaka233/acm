#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 1000005;

int a[N];
int b[N];
int vis1[N];
int vis2[N];
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis1,0,sizeof(vis1));
        //memset(vis2,0,sizeof(vis2));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        int ans = 0;
        int flag;
        for(int i=1;i<=n;i++)
        {
            int flag = i;
            if(a[flag]==b[flag])
            {
                vis1[flag]=1;
                continue;
            }
            else if(vis1[flag]==0)
            {
                ans++;
            }
            while(vis1[flag]!=1)
            {
                vis1[flag]=1;
                for(int j=1;j<=n;j++)
                {
                    if(b[flag]==a[j])
                    {
                        flag=j;
                        break;
                    }
                }

            }

        }
        printf("%d\n",n-ans);
    }
    return 0;
}
