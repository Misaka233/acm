#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans;

int a[10000010];

int main()
{
    int i,j,t;
        cin>>t;
        a[1]=0;
        a[2]=0;
        a[3]=1;
        for(i=4;i<=10000000;i++){
            if(i%2==0){
                int tt=i/2;
                a[i]=a[tt]*2;
            }
            else{
                int tt=i/2;
                a[i]=a[tt]+a[tt+1]+1;
            }
        }
    while(t--)
    {
        scanf("%d",&n);
        cout<<a[n]<<endl;
    }
    return 0;
}
