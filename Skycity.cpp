#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int R , r , H , F , S;
double radius , ans , height , dr , pi = acos(-1.);
double check()
{
    int top = 3 , mid , bot = 1e5;
    double res = 1e60;
    while (top < bot)
    {
        mid = top + bot + 1 >> 1;
        double theta = pi / mid;
        double area = (2 * radius * tan(theta)) * height;
        if (area >= S)
            top = mid , res = area * mid;
        else bot = mid - 1;
    }
    return res;
}


int main()
{
    while (~scanf("%d%d%d%d%d",&R , &r , &H , &F , &S))
        {
            ans = 0 , height = 1. * H / F , dr = 1. * (R - r) / F , radius = r;
            for (int i = 0 ; i < F ; ++ i , radius += dr)
            ans += check();
            printf("%f\n" , ans);
        }
    return 0;
}
