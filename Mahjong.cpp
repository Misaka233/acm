#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int cnt[37];
bool judge4X3()
{
    int re=0;
    int tmp[37];
    for(int i=0;i<34;i++)
    {
        tmp[i]=cnt[i];
    }
    for(int i=0;i<=18;i+=9)
    {
        for(int j=0;j<9;j++)
        {
            if(tmp[i+j]>=3)
            {
                tmp[i+j]-=3;
                re++;
            }
            while(j<7&&tmp[i+j]&&tmp[i+j+1]&&tmp[i+j+2])
            {
                tmp[i+j]--;
                tmp[i+j+1]--;
                tmp[i+j+2]--;
                re++;
            }

        }
    }
    for(int j=0;j<7;j++)
    {
        if(tmp[j+27]>=3)
        {
            tmp[j+27]-=3;
            re++;
        }
    }
    if(re==4) return true;
    return false;
}
bool judge1()
{
    for(int i=0;i<34;i++)
    {
        if(cnt[i]>=2)
        {
            cnt[i]-=2;
            if(judge4X3())
            {
                cnt[i]+=2;
                return true;
            }
            cnt[i]+=2;
        }
    }
    return false;
}
bool judge2()
{
    for(int i=0;i<34;i++)
    {
        if(cnt[i]!=2&&cnt[i]!=0)
        {
            return false;
        }
    }
    return true;
}
bool judge3()
{
    for(int j=0;j<7;j++)
    {
        if(cnt[j+27]==0)
            return false;
    }
    for(int i=0;i<=18;i+=9)
    {
        if(cnt[i]==0||cnt[i+8]==0) return false;
        for(int j=1;j<8;j++)
        {
            if(cnt[i+j]!=0)
                return false;
        }
    }
    return true;
}
bool judge()
{
    if(judge1()||judge2()||judge3()) return true;
    else return false;
}
int main()
{
    int t;
    char st[10];
    int ans[37],tot;
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<13;i++)
        {
            scanf("%s",&st);
            int tt=st[0]-'1';
            if(st[1]=='m') tt+=0;
            else if(st[1]=='s') tt+=9;
            else if(st[1]=='p') tt+=18;
            else tt+=27;
            cnt[tt]++;
        }
        tot=0;
        for(int i=0;i<34;i++)
        {
            cnt[i]++;
            if(cnt[i]<=4&&judge())
                ans[tot++]=i;
            cnt[i]--;
        }
       if(tot==0)printf("Nooten\n");
        else
        {
            printf("%d",tot);
            for(int i=0;i<tot;i++)
            {
                printf(" %d",(ans[i]%9)+1);
                if(ans[i]/9==0)printf("m");
                else if(ans[i]/9==1)printf("s");
                else if(ans[i]/9==2)printf("p");
                else printf("c");
            }
            printf("\n");
        }
    }
    return 0;
}
