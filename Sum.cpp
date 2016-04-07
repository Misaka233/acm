#include<iostream>
#include<cstdio>
#include<cmath>
int main()
{
    int s;
    scanf("%d",&s);
    int n=(int)sqrt(2.0*s);
    if(n*n+n<s*2) n++;
    if((s-n*(n+1)/2)%2==0)
        printf("%d\n",n);
    else
    {
        if(n%2) printf("%d\n",n+2);
        else printf("%d\n",n+1);
    }
    return 0;
}
