#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n,k,kk,flag,zero;
int main()
{
    scanf("%d%d",&n,&k);
    flag=1;
    zero=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==k)
            kk=a[i];
        if(i>k&&kk!=a[i])
            flag=0;
    }
    if(flag==0) cout<<-1<<endl;
    else
    {
        if(zero==1) cout<<0<<endl;
        else
        {
            int i;
            for(i=k;i>=1;i--)
            {
                if(a[i]!=kk)
                {
                    cout<<i<<endl;
                    break;
                }
            }
            if(i==0) cout<<0<<endl;
        }
    }
    return 0;
}
