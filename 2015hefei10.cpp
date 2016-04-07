#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include "list"
#include<vector>
#include<time.h>
#include<assert.h>
typedef long long  ll;
using namespace std;

int ans[100005];
struct DATA
{
    int h,k;
    bool operator < (const DATA &a) const {
        return h>a.h;
    }
}data[100005];

int lbigger[100005];

int sum[400005];
int p;
void updata(int l,int r,int o)
{
    if(l == r)
    {
        sum[0]++;
        return ;
    }
    else {
        int mid = (l+r)>>1;
        if(p<=mid)updata(l,mid,o*2);
        else updata(mid+1,r,o*2+1);
        sum[o] = sum[o*2]+sum[o*2+1];
    }
}
int query(int l,int r,int o,int tot)
{
    if(l == r)return l;
    int mid = (l+r)>>1;
    if(mid-l+1-sum[o*2]>tot)
    {
        return query(l,mid,o*2,tot);
    }
    else
    {
        return query(mid+1,r,o*2+1,tot-mid-l+1-sum[o*2]);
    }
}

int main()
{
//    freopen("data.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int kase = 0;
    while(T--){
        printf("Case #%d: ",++kase);
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;++i){
            scanf("%d%d",&data[i].h,&data[i].k);
        }
        sort(data,data+n);
        bool can = 1;
        for(int i = 0;i<n;++i){
            if(data[i].k>i)
            {
                 printf("impossible\n");
                 can = 0;
                 break;
            }
            else
            {
                lbigger[i] = min(data[i].k,i - data[i].k);
            }
        }
        if(!can)
        {
            continue;
        }
        memset(sum,0,sizeof(sum));
        for(int i = n-1;i>=0;--i){
            int tot = lbigger[i];
            int pos = query(1,n,1,tot);
            ans[pos] = data[i].h;
            p = pos;
            updata(1,n,1);
        }
        printf("%d",ans[1]);
        for(int i = 2;i<=n;++i){
            printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
