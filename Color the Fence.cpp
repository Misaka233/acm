#include <bits/stdc++.h>
using namespace std;
int a[12];
int main()
{
    int value,cnt;
    scanf("%d",&value);
    int mmin =100010;
    for(int i=1; i<=9; i++)
    {
        scanf("%d",&a[i]);
        if(mmin > a[i]) mmin = a[i];
    }
    if(value < mmin)
    {
        printf("-1\n");
        return 0;
    }
    cnt = value / mmin;
    for(int i=cnt-1; i>=0; i--)
    {
        for(int j=9; j>=1; j--)
        {
            if(value >= a[j] && (value - a[j]) / mmin >= i)
            {
                printf("%d",j);
                value -= a[j];
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
