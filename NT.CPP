
/*
 * ���⣺������[x , y]��beautiful number�ĸ�����
 * a positive integer number is beautiful if and only
 * if it is divisible by each of its nonzero digits.
������һ�����ܱ��������з�����λ���������ܱ����ǵ���С��������������1��9����С������Ϊ2520��
��λDPʱ����ֻ�豣��ǰ����Щλ����С�������Ϳɽ���״̬ת�ƣ����߽�ʱ�Ͱ�����λ��lcm����ˣ�
Ϊ���ж�������ܷ�����������λ���������ǻ���Ҫ�������ֵ����ȻҪ��¼ֵ�ǲ����ܵģ���ʵ����ֻ
���¼����2520��ģ���ɣ��������ǾͿ�����Ƴ�������λDP��dfs(pos,mod,lcm,f),posΪ��ǰ
λ��modΪǰ����Щλ��2520��ģ��lcmΪǰ����Щ��λ����С��������f���ǰ����Щλ�Ƿ�ﵽ���ޣ�
����һ��dp�����Ҫ����19*2520*2520�����Գ��ڴ��ˣ����ǵ���С����������ɢ�ģ�1-2520�п���
����С����������ʵֻ��48����������ɢ��������dp��������һά���Խ���48�������Ͳ��ᳬ�ˡ�
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
long long dp[20][1<<8][2520];//���� ѡȡ���� ����
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