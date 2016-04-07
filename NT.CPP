
/*
 * 题意：求区间[x , y]中beautiful number的个数，
 * a positive integer number is beautiful if and only
 * if it is divisible by each of its nonzero digits.
分析：一个数能被它的所有非零数位整除，则能被它们的最小公倍数整除，而1到9的最小公倍数为2520，
数位DP时我们只需保存前面那些位的最小公倍数就可进行状态转移，到边界时就把所有位的lcm求出了，
为了判断这个数能否被它的所有数位整除，我们还需要这个数的值，显然要记录值是不可能的，其实我们只
需记录它对2520的模即可，这样我们就可以设计出如下数位DP：dfs(pos,mod,lcm,f),pos为当前
位，mod为前面那些位对2520的模，lcm为前面那些数位的最小公倍数，f标记前面那些位是否达到上限，
这样一来dp数组就要开到19*2520*2520，明显超内存了，考虑到最小公倍数是离散的，1-2520中可能
是最小公倍数的其实只有48个，经过离散化处理后，dp数组的最后一维可以降到48，这样就不会超了。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
long long dp[20][1<<8][2520];//长度 选取数字 余数
int digit[20];
const int mod=2520;
long long dfs(int len,int mask,int num,bool fp)
{
    if(!len)
    {
        for(int i=0;i<8;i++)
        {
            if(mask&(1<<i)&&num%(i+2)!=0)
                return 0;
        }
        return 1;
    }
    if(!fp&&dp[len][mask][num]!=-1)
        return dp[len][mask][num];
    int fpmax=fp?digit[len]:9;
    long long ret=0;
    for(int i=0;i<=fpmax;i++)
    {
        ret+=dfs(len-1,i<2?mask:mask|1<<(i-2),(num*10+i)%mod,fp&&i==fpmax);

    }
    if(!fp)
    {
        dp[len][mask][num]=ret;
    }
    return ret;
}
long long f(long long n)
{
    int len=0;
    while(n)
    {
        digit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,0,true);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int t;
    long long a,b;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b;
        cout<<f(b)-f(a-1)<<endl;
    }
    return 0;
}
