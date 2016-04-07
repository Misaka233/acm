#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int mat[maxn][maxn];
int h[maxn];
int l[maxn],r[maxn];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(h,0,sizeof(h));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mat[i][j]==0)
                    h[j]++;
                else
                    h[j]=0;
            }
            for(int j=1;j<=m;j++)
            {
                l[j]=j;
                while(l[j]>1&&h[j]<=h[l[j]-1])
                    l[j]=l[l[j]-1];
            }
            for(int j=m;j>=1;j--)
            {
                r[j]=j;
                while(r[j]<m&&h[j]<=h[r[j]+1])
                    r[j]=r[r[j]+1];
            }
            for(int j=1;j<=m;j++)
            {
                if(ans<h[j]*(r[j]-l[j]+1))
                    ans=h[j]*(r[j]-l[j]+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
