//dp[i][state] = sum(dp[i-1][state']);   state = 1<<(p-1) || state'  ||  ((state'<<p) &SIZE) ; 1<=p<=min(k,L); //SIZE=(1<<k)-1;
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
LL dp[1<<22];

int main()
{
    int t, n, k, L;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d", &n, &k, &L);
        int MIN = min(L, k);
        int SIZE = (1<<k)-1;
        memset(dp, 0, sizeof dp );
        dp[0] = 1;
        for(int i=0; i<n; ++i)
        {
            for(int j=SIZE; j>=0; --j) if(dp[j]>0)
            {
                LL tmp = dp[j];
                for(int p=1; p<=MIN; ++p)
                {
                    int next=(1<<(p-1))|j|((j<<p)&SIZE);
                    //加上p本身这个数 + 原来可取到的数 + 原来可取到的数加上p之后的数，即组成了所有加上p之后的情况
                    dp[next] =dp[next] + tmp;
                    if(dp[next]>mod) dp[next] -= mod;
                }

                if(k<L)//第i个数选大于k的数
                {
                        dp[j] = dp[j] +  (LL)tmp*(L-k);
                        if(dp[j]>mod) dp[j] -= mod;
                }

            }
        }
        LL ans = 0;
        for(int i=0; i<=SIZE; ++i) if(i&(1<<(k-1)))
        {
            ans = ans + dp[i];
            if(ans>mod) ans -= mod;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
