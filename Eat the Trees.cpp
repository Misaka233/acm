#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int n,m,cas;
int v[12][12];
long long dp[12][12][1<<12];

void solve()
{
    memset(dp,0,sizeof(dp));
    dp[0][m][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            dp[i][0][j<<1]=dp[i-1][m][j];
        }

        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<1<<m<<1;k++)
            {
                int p=1<<j;
                int q=p>>1;
                bool x=k&p;
                bool y=k&q;
                if(v[i][j])
                {
                    dp[i][j][k]=dp[i][j-1][k^p^q];
                    if(x!=y)
                        dp[i][j][k]+=dp[i][j-1][k];
                }
                else
                {
                    if(x==0&&y==0)
                        dp[i][j][k]=dp[i][j-1][k];
                    else
                        dp[i][j][k]=0;
                }
            }
     }
    }
    //cout<<dp[n][m][0];
    printf("Case %d: There are %I64d ways to eat the trees.\n",cas,dp[n][m][0]);

}
int main()
{
    int t;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&v[i][j]);
            }
        }
        solve();
    }
    return 0;
}


/*
#include<iostream>

using namespace std;

int mat[100][100];

__int64 dp[12][12][1<<12];

int main()

{

    // freopen("1.txt","r",stdin);

    int zu;

    int g=1;

    scanf("%d",&zu);

    while(zu--)

    {

        int m,n;

        scanf("%d%d",&m,&n);

        int i,j,k;

        for(i=1;i<=m;i++)

            for(j=1;j<=n;j++)

                scanf("%d",&mat[i][j]);

            //memset(dp,0,sizeof(dp));

            dp[0][n][0]=1;

            for(i=1;i<=m;i++)

            {

                for(j=0;j<(1<<n);j++)

                    dp[i][0][j<<1]=dp[i-1][n][j];

                //�����ұߵ�ȥ�� �����е�״̬������һ�в����к����ĸı�(ע������ߵ��ǵ�λ����������)

                //��һ�����ұߵı߸�һ�������������غ� ��һ������ߵı߸�Ҳһ�������������غ�

                //���Խ��е�����һ������״̬(Ҳ����������)���ҵ�һ�λ���

                    for(j=1;j<=n;j++)//ö�پ����ߵĹ���

                    {

                        for(k=0;k<(1<<n<<1);k++)//ö��������

                        {

                            int p=1<<j;//��j��������(��)

                            int q=p>>1;//��j-1��������(��)

                            bool x=k&p;//�������Ƿ���ͨ·�ཻ

                            bool y=k&q;//�������Ƿ���ͨ·�ཻ



                            //�ж���������[i,j]Ϊ����ʱ�ķֲ� ÿ��������1<<n<<1�� ��׶ξ���



                            if(mat[i][j])//����õ�Ԫ����ͨ��

                            {

                                dp[i][j][k]=dp[i][j-1][k^p^q];//��Ȼ��һ��ͨ·������һ�����ͨ·

                                if(x!=y)

                                    dp[i][j][k]+=dp[i][j-1][k];//��һ���¸������������һ�����

                            }

                            else//����Ϊ�ϰ�����

                            {

                                if(x==0&&y==0)//ͨ·�������߲��ཻ

                                    dp[i][j][k]=dp[i][j-1][k];//ֱ��ת��

                                else

                                    dp[i][j][k]=0;//ͨ·���������ཻ�ķ���һ��Ϊ0

                            }

                        }

                    }

            }

            printf("Case %d: There are %I64d ways to eat the trees.\n",g++,dp[m][n][0]);

    }

    return 0;

}*/