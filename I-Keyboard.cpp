#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=107;
int dp[maxn][maxn];//前i个按键，j结尾
int g[maxn][maxn];
int a[maxn];
char keys[maxn],letters[maxn];
int K,L,s;
int cost(int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=a[i]*(i-l+1);
    }
    return sum;
}
void prints(char s[],int l,int r)
{
    int i;
    for(i=l;i<=r;i++) printf("%c",s[i]);
}
void output(int key,int letter)
{
    if(key>1)
    {
        output(key-1,g[key][letter]);
    }
    printf("%c: ",keys[key-1]);
    prints(letters,g[key][letter],letter-1);
    puts("");
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&K,&L);
        scanf("%s%s",keys,letters);
        for(int i=1;i<=L;i++)
            scanf("%d",&a[i]);
        for(int j=1;j<=L;j++)
            dp[1][j]=cost(1,j);

        for(int i=2;i<=K;i++)
        {
            for(int j=1;j<=L;j++)
            {
                dp[i][j]=dp[i-1][i-1]+cost(i,j);
                g[i][j]=i-1;
                for(int n=i;n<j;n++)
                {

                    s=dp[i-1][n]+cost(n+1,j);
                    if(dp[i][j]>s)
                    {
                        dp[i][j]=s;
                        g[i][j]=n;
                    }
                }
            }
        }
        printf("Keypad #%d:\n",cas);
        int i,j;
         for(i=j=1;i<=K;i++)
        {
            if(dp[i][L]<dp[j][L]) j=i;
        }
        output(K,L);
        puts("");
    }
    return 0;
}
