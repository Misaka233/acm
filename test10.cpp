#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;


int str[N];
int a[N];

int func(int a[],int b[],int n){
    int i;
    for(i = 0; i < n - 1; i++)
        if((a[i] == a[i + 1]  && b[i] == b[i+1])||
            (a[i] < a[i + 1]  && b[i] < b[i+1])||
            (a[i] > a[i + 1]  && b[i] > b[i+1]))
            continue;
        else
            break;
    if(i == n - 1)
        return 1;
    else
        return 0;
}

int main()
{
    int n,m,k,i,j;
    while(scanf("%d %d %d",&n,&m,&k)!= EOF){
        for(i = 0; i < n; i++)
            scanf("%d",&str[i]);

        for(j = 0; j < m; j++)
            scanf("%d", &a[j]);

        int ans = 0;
        for(i = 0; i < n - m + 1;){
            if(func(a,&str[i],m))
                i = i + m,ans++;
            else
                i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
