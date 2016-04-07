#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
bool ju(int num)
{
    if(num==2||num==3||num==5)
       return true;
    unsigned long c=7;
    if(num%2==0||num%3==0||num%5==0||num==1)
        return false;
    int maxc=int(sqrt(num));
    while(c<=maxc)
    {
        if(num%c==0)
           return false;
        c+=4;
        if(num%c==0)
           return false;
        c+=2;
        if(num%c==0)
           return false;
        c+=4;
        if(num%c==0)
           return false;
        c+=2;
        if(num%c==0)
           return false;
        c+=4;
        if(num%c==0)
           return false;
        c+=6;
        if(num%c==0)
           return false;
        c+=2;
        if(num%c==0)
            return false;
        c+=6;
    }
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1||n==2) {printf("1\n");continue;}
        if(n==4) {printf("2\n");continue;}
        if(ju(n)==0) {printf("0\n");continue;}
        if(ju(n)==1) {printf("%d\n",n-1);continue;}
    }
}
