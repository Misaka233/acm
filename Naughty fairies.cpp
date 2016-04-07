#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int maxn=2005;
const int w=2000;
struct ten
{
    int l;
    int a[maxn];
    void init(char *ss)
    {
        memset(a,0,sizeof(a));
        l=strlen(ss);
        for(int i=1;i<=l;i++) a[i]=ss[l-i]-48;
    }
    void chen2()
    {
        for(int i=1;i<=l;i++) a[i]+=a[i];
        for(int i=1;i<=l;i++) if(a[i]>=10)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        while(a[l+1]) l++;
    }
    void jia1()
    {
        a[1]+=1;
        for(int i=1;i<=l;i++) if(a[i]>=10)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        while(a[l+1]) l++;
    }
    void print()
    {
        for(int i=l;i>=1;i--) printf("%d",a[i]);
        if(l==0) printf("0");
        printf("\n");
    }
    int div2()
    {
        int g=0;
        for(int i=l;i>=1;i--)
        {
            g=g*10+a[i];
            a[i]=g/2;
            g=g%2;
        }
        while(l&&a[l]==0) l--;
        return g;
    }
};
struct two
{
    int l;
    int a[maxn];
    void init(ten& ten)
    {
        memset(a,0,sizeof(a)); l=0;
        while(ten.l)
        {
            l++;
            a[l]=ten.div2();
        }
    }
    void print()
    {
        for(int i=l;i>=1;i--) printf("%d",a[i]);
        if(l==0) printf("0");
        printf("\n");
    }
};
ten tenn,tenm,node1,node2;
two n,m;
char s1[maxn],s2[maxn];
void res(ten& ten,two& two)
{
    memset(ten.a,0,sizeof(ten.a));ten.l=0;
    for(int i=two.l;i>=1;i--)
    {
        ten.chen2();
        if(two.a[i]) ten.jia1();
    }
}
bool operator > (two& k1,two& k2)
{
    while(k1.l&&k1.a[k1.l]==0) k1.l--;
    while(k2.l&&k2.a[k2.l]==0) k2.l--;
    if(k1.l!=k2.l) return k1.l>k2.l;
    for(int i=k1.l;i>=1;i--)
    if(k1.a[i]!=k2.a[i]) return k1.a[i]>k2.a[i];
    return  false;
}
two operator - (two& k1,two& k2)
{
    two k3;
    k3=k1;
    for(int i=1;i<=k3.l;i++)
    {
        k3.a[i]-=k2.a[i];
        if(k3.a[i]<0)
        {
            k3.a[i]+=2;
            k3.a[i+1]--;
        }
    }
    while(k3.a[k3.l]==0&&k3.l) k3.l--;
    return k3;
}
two operator + (two k1,int k2)
{
    k1.a[1]+=k2;
    if(k1.a[k1.l+1]) k1.l++;
    for(int i=1;i<=k1.l;i++)
    if(k1.a[i]>=2)
    {
        k1.a[i+1]+=k1.a[i]/2;
        k1.a[i]%=2;
        if(k1.a[k1.l+1]) k1.l++;
    }
    return k1;
}
int calc(int s,int t)
{
    int k1,k2,k3,k4;
    k1=0;k2=1;
    if(t) swap(k1,k2);
    for(int i=s;i>=1;i--)
    {
        if(n.a[i])
        {
            k3=min(k1+2,k2+2);
            k4=min(k1+2,k2+1);
        }
        else
        {
            k3=min(k1+1,k2+2);
            k4=min(k1+2,k2+2);
        }
        k1=k3;k2=k4;
    }
    return k1;
}
void solve()
{
    two ans,g,des;
    ten tenasn;
    memset(ans.a,0,sizeof(ans.a));ans.l=0;
    tenn.init(s1);tenm.init(s2);
    node1=tenn;node2=tenm;
    n.init(node1);m.init(node2);
    if(m>n)
    {
        ans=m-n;
        res(tenasn,ans);
        tenasn.print();
        return;
    }
    memset(des.a,0,sizeof(des.a));des.l=m.l;
    for(int i=1;i<=des.l;i++) des.a[i]=n.a[i+n.l-des.l];
    if(m>des) ans=(m-des)+calc(n.l-des.l,0);
    else ans=(des-m)+calc(n.l-des.l,0);
    if(m>des) g=(m-des)+(calc(n.l-des.l,1)-1);
    else g=(des-m)+(calc(n.l-des.l,1)+1);
    if(ans>g) ans=g;
    if(des.l)
    {
        for(int i=1;i<des.l;i++) des.a[i]=des.a[i+1];des.a[des.l]=0;des.l--;
        g=(m-des)+(calc(n.l-des.l,1)-1);
        if(ans>g) ans=g;
    }
    if(m.l<n.l)
    {
        memset(des.a,0,sizeof(des.a));
        des.l=m.l+1;
        for(int i=1;i<=des.l;i++) des.a[i]=n.a[i+n.l-des.l];
        g=(des-m)+calc(n.l-des.l,0);
        if(ans>g) ans=g;
    }
    res(tenasn,ans);
    tenasn.print();
}
int main()
{
    //freopen("data.txt","r",stdin);
    while(cin>>s1)
    {
        cin>>s2;
        if(strlen(s1)==1&&s1[0]=='0') break;

        solve();
    }
    return 0;
}
