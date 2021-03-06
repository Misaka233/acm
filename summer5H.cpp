#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;
typedef __int64 LL;
const int N = 50010;
const int M = N * 5;

char ch[N][8];
int chd[M][64];
int val[M];
int ID[130];
LL cnt[34];

void init()
{
    int ct = 1;
    for(int i = 0; i < 10; i ++) ID['0' + i] = ct ++;
    for(int i = 0; i < 26; i ++) ID['a' + i] = ct ++;
    for(int i = 0; i < 26; i ++) ID['A' + i] = ct ++;
}

int main()
{
    int sz, n;
    init();
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%s", ch[i]);
        }
        for(int i = 1; i < 32; i ++)
        {
            CLR(chd[0], 0);sz = 1;cnt[i] = 0;
            for(int j = 0; j < n; j ++)
            {
                int p = 0;
                for(int k = 0; k < 5; k ++) if(i & (1 << k))
                {
                    int c = ID[ch[j][k]];
                    if(!chd[p][c])
                    {
                        val[sz] = 0;
                        CLR(chd[sz], 0);
                        chd[p][c] = sz ++;
                    }
                    p = chd[p][c];
                }
                val[p] ++;
            }
            for(int j = 1; j < sz; j ++)
            {
                if(val[j])
                {
                    LL tmp = val[j];
                    cnt[i] += tmp * (tmp - 1) / 2;
                }
            }
        }
        LL d[6], ans[6], tot = (LL)n * (n - 1) / 2;
        CLR(d, 0);
        for(int i = 1; i < 32; i ++)
        {
            int tmp = i, ct = 0;
            while(tmp)
            {
                if(tmp & 1)ct ++;
                tmp >>= 1;
            }
            d[ct] += cnt[i];
        }
        ans[5] = d[5];
        ans[4] = d[4] - 5 * ans[5];
        ans[3] = d[3] - 10 * ans[5] - 4 * ans[4];
        ans[2] = d[2] - 10 * ans[5] - 6 * ans[4]  - 3 * ans[3];
        ans[1] = d[1] - 2 * ans[2] - 3 * ans[3] - 4 * ans[4] - 5 * ans[5];
        ans[0] = tot - ans[1] - ans[2] - ans[3] - ans[4] - ans[5];
        printf("%I64d", ans[5]);
        for(int i = 4; i >= 0; i --)
        {
            printf(" %I64d", ans[i]);
        }puts("");
    }
}
