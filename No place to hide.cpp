#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int maxn=1007;
const double eps=1e-10;
const double pi=acos(-1.0);
double dcmp(double x) {return (x>eps)-(x<-eps);}
double sqr(double x) {return x*x;}
struct misaka
{
    double x,y,v;
    double dis(misaka &b){return sqrt(sqr(x-b.x)+sqr(y-b.y));}
};
misaka p[maxn],th;
int n;
void am(double &x)
{
    while(x + pi < -eps) x += pi + pi;
    while(x - pi > -eps) x -= pi + pi;
}
 double ca(double s, double e)
{return e > s + eps ? e - s : pi + pi + e - s;}
struct cov
{
    double s,e;
    void read(double s_,double e_)
    {
        am(s_);am(e_);
        s=s_;e=e_;
    }
    bool operator<(const cov &b)const
    {
        if(!dcmp(s-b.s)) return ca(s,e)>ca(b.s,b.e);
        return s<b.s;
    }
}cover[maxn],cc[maxn];
int main()
{
    int t, i, j, k, ans, cnt;
    bool flag;
    for(scanf("%d", &t); t --; )
    {
        flag = false;
        scanf("%d", &n);
        scanf("%lf%lf%lf", &th.v, &th.x, &th.y);
        for(i = 0; i < n; ++ i)
        {
            scanf("%lf%lf%lf", &p[i].v, &p[i].x, &p[i].y);
            if(p[i].v > th.v + eps || !dcmp(p[i].dis(th))) flag = true;
        }
        if(flag) {printf("1\n"); continue;}
        if(!dcmp(th.v)) {printf("0\n"); continue;}
        for(i = 0; i < n; ++ i)
        {
            double ang = atan2(p[i].y - th.y, p[i].x - th.x);
            if(p[i].v > th.v - eps)
            {
                cover[i].read(ang - pi * 0.5, ang + pi * 0.5);
                continue;
            }
            double c = p[i].dis(th);
            double T = sqrt(sqr(c)/ (sqr(th.v) - sqr(p[i].v)));
            double cs = acos(c / T / th.v);
            cover[i].read(ang - cs, ang + cs);
        }
        sort(cover, cover + n);
        for(i = k = 1; i < n; ++ i)

        if(dcmp(cover[i].s - cover[i-1].s)) cover[k ++] = cover[i];
            n = k;
        for(i = 0, ans = 0x3f3f3f3f; i < n; ++ i)
        {
            for(j = i, k = 0; ; j = (j + 1) % n)
            {
                cc[k].read(cover[j].s - cover[i].s - pi, cover[j].e - cover[i].s - pi);
                if(cc[k].s > cc[k].e) cc[k].e = pi + pi;
                ++ k;
                if(j == (i + n - 1) % n) break;
            }
            double now = -pi - pi, nex = -pi;
            flag = false;
            for(j = cnt = 0; j < n; ++ j)
            {
                if(cc[j].e < now + eps) continue;
                if(cc[j].s > nex + eps) break;
                if(cc[j].s > now + eps)
                {
                    ++ cnt;
                    now = nex;
                }
                if(cc[j].e > nex + eps) nex = cc[j].e;
                if(nex > pi - eps) {flag = true; break;}
            }
            if(flag) ans = min(ans, cnt);
        }
        if(ans == 0x3f3f3f3f) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
