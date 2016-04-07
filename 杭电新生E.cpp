#include<iostream>
#include<cmath>
#inlcud<cstdio>
using namespace std;
int sum[25][25];
int t1,t2,t3;
int main()
{
    sum[1][1]=1;
    sum[2][1]=1;
    sum[2][2]=1;
    sum[3][1]=1;
    sum[3][2]=3;
    sum[3][3]=1;
    for(int i=4;i<25;i++)
    {
        sum[i][1]=1;
        sum[i][i]=1;
        for(int j=2;j<i;j++)
        {
            sum[i][j]=sum[i-1][j]*j+sum[i-1][j-1];
        }
    }

}
