#include<bits/stdc++.h>
using namespace std;
const int INF=1<<31;
const int maxn=1111;
typedef long long ll;

int kase, n, a[maxn], c[maxn], dp[maxn][maxn];
int main(){
    scanf("%d",&kase);
    for(int ks=1;ks<=kase;ks++)
    {
        cin>>n;
        printf("Case #%d: ", ks);
        int ma=0;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            ma=max(ma, a[i]);
        }
        sort(a,a+n);
        memset(c,0,sizeof(c));

        for(int i=0; i<n; i++){
            int j=a[i];
            while(c[j] && j>0) j--;//j回合没需要杀的就往前推一个回合
            if(j>0){
                c[j]=a[i]-j+1;//第j回合砍死B砍了j-1刀，所以需要a-（j-1）刀
            }
        }
      for(int i=0;i<n;i++)
         cout<<c[i]<<" ";
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=ma;i++)
            {
            for(int j=0;j<=i;j++){
                if(j>0)    dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
                if(c[i] && j+c[i]-1<i)
                    dp[i][j] = max(dp[i][j], dp[i-1][j+c[i]-1]+1);
            }
        }
        int ans=0;
        for(int j=0;j<=ma;j++)    ans = max(dp[ma][j], ans);
        printf("%d\n",ans);
    }
    return 0;
}

