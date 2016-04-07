/*sort() // 将活动按照b/c的值，从大到小排序
For i = 1 .. N // 枚举活动种类
    For v = c[i] .. M-1 // 枚举背包容量
        For j = 1 .. K // 枚举举办次数
            totalTime = c[i] * j
            If (totalTime > v) Thne
                // 举办j次，超过了背包容量
                Break
            End If
            tempValue = calc(v - totalTime, j, i)
            // 计算从v - totalTime开始连续进行j次活动i的得到的价值
            // 这个可以用数学方法进行计算，因此时间复杂度为O(1)
            If (f[i][v] < f[i - 1][v - totalTime] + tempValue) Then
                f[i][v] = f[i - 1][v - totalTime] + tempValue
            End If
        End For
    End For
End For



*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct misaka
{
    int a,b,c,d;
}q[1005];
int f[1005][1005];
int p[1005];
bool cmp(misaka a,misaka b)
{
    return a.d>b.d;
}

int main()
{
    int n,m,k,tempValue,totalTime;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
        q[i].d=q[i].b/q[i].c;
    }
    sort(q,q+n,cmp);
    tempValue=0;
    for(int i=1;i<=n;i++)
        p[i]=m;
    for(int i=1;i<=n;i++)
    {
        for(int v=q[i].c;v<=m-1;v++)
        {
            for(int j=1;j<=k;j++)
            {

                totalTime=q[i].c*j;
                if(totalTime>v) break;
                else
                {
                    //tempValue = calc(v - totalTime, j, i)
                    tempValue+=q[i].a-m*q[i].b+q[i].b*(m-v+totalTime-(j-1)*q[i].c);

                // 计算从v - totalTime开始连续进行j次活动i的得到的价值
                // 这个可以用数学方法进行计算，因此时间复杂度为O(1)
                    if(f[i][v] < f[i - 1][v - totalTime] + tempValue)
                        f[i][v] = f[i - 1][v - totalTime] + tempValue;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        ans=max(ans,f[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}
