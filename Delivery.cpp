#include<bits/stdc++.h>
using namespace std;
double k[1010];
int main()
{

    int t;
    double a;
    scanf("%d",&t);
    int n;
    int cas=0;
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        double ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&a);
            ans+=a;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&a);
        }
        printf("Case #%d: %.6f\n",cas,(n+1)/ans);
    }
    return 0;
}
