#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m%(n+1)==0)
        {
            cout<<"none"<<endl;
            continue;
        }
        else
        {
            if(n<m)
            {
                cout<<m%(n+1)<<endl;
            }
            else
            {
                for(int i=m;i<n;i++)
                {
                    cout<<i<<" ";
                }
                cout<<n<<endl;
            }
        }
    }
    return 0;
}
