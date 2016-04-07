#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int fangxiang[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool a[1005][1005][2], f1,f2;
int main()
{
    int n,r1,c1,d1,r2,c2,d2,r,c;
    while(cin>>n)
    {
        if(n==0) break;
        cin>>r1>>c1>>d1>>r2>>c2>>d2;
        memset(a,false,sizeof(a));
        f1=true;f2=true;
        while(f1||f2)
        {
            if(r1==r2&&c1==c2) break;
            if(f1)
            {
                a[r1][c1][0]=true;
                r=r1+fangxiang[d1][0];
                c=c1+fangxiang[d1][1];
                if(r<0 || r==n || c<0 || c==n || a[r][c][0])
                {
                    d1++;
                    if(d1==4) d1=0;
                    r=r1+fangxiang[d1][0];
                    c=c1+fangxiang[d1][1];
                    if(r<0 || r==n || c<0 || c==n || a[r][c][0])
                        f1=false;
                    else
                        {r1=r;c1=c;}
                }
                else
                    {r1=r;c1=c;}
            }
            if(f2)
            {
                a[r2][c2][1]=true;
                r=r2+fangxiang[d2][0];
                c=c2+fangxiang[d2][1];
                if(r<0||r==n||c<0||c==n||a[r][c][1])
                {
                    d2--;
                    if(d2<0) d2=3;
                    r=r2+fangxiang[d2][0];
                    c=c2+fangxiang[d2][1];
                    if(r<0||r==n||c<0||c==n||a[r][c][1])
                        f2=false;
                    else
                        {r2=r;c2=c;}
                }
                else
                    {r2=r;c2=c;}
            }
        }
        if(r1==r2&&c1==c2)
            cout<<r1<<" "<<c1<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
