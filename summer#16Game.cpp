#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            ans^=x;
        }
        if(ans) printf("Win\n");
        else printf("Lose\n");
    }
    return 0;
}
