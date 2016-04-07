#include <iostream>
#include <cstring>
using namespace std;
double d[32][32][1805],g[32][32];
int main()
{
	int t,i2,i,j,k;
	cin>>t;
	for(i2=0;i2<t;i2++)
	{
		int n,m,x,y;
		double sum;
		for(i=0;i<32;i++)
			for(j=0;j<32;j++)
				for(k=0;k<1805;k++)
					d[i][j][k]=-1;
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>g[i][j];
		d[0][0][int(g[0][0])]=0;
		for(y=1;y<m;y++)
			for(sum=0;sum<1802;sum++)
			{
				if(sum-g[0][y]>=0&&d[0][y-1][(int)(sum-g[0][y])]!=-1)
					d[0][y][(int)sum]=d[0][y-1][(int)(sum-g[0][y])]+g[0][y]*g[0][y]-sum*sum/(y+1)+(sum-g[0][y])*(sum-g[0][y])/y;
			}
		for(x=1;x<n;x++)
			for(sum=0;sum<1802;sum++)
			{
				if(sum-g[x][0]>=0&&d[x-1][0][int(sum-g[x][0])]!=-1)
					d[x][0][int(sum)]=d[x-1][0][int(sum-g[x][0])]+g[x][0]*g[x][0]+(sum-g[x][0])*(sum-g[x][0])/x-sum*sum/(x+1);
			}
		for(x=1;x<n;x++)
			for(y=1;y<m;y++)
				for(sum=0;sum<1803;sum++)
				{
					double min2=999999999,tem=0;
					if(sum-g[x][y]>=0&&d[x][y-1][int(sum-g[x][y])]!=-1)
					{
						double e;
						e=d[x][y-1][int(sum-g[x][y])]+g[x][y]*g[x][y];
						e=e-sum*sum/(x+y+1)+(sum-g[x][y])*(sum-g[x][y])/(x+y);
						if(e<min2)min2=e;
						tem=1;
					}
					if(sum-g[x][y]>=0&&d[x-1][y][int(sum-g[x][y])]!=-1)
					{
						double e;
						e=d[x-1][y][int(sum-g[x][y])]+g[x][y]*g[x][y];
						e=e-sum*sum/(x+y+1)+(sum-g[x][y])*(sum-g[x][y])/(x+y);
						if(e<min2)min2=e;
						tem=1;
					}
					if(tem)d[x][y][int(sum)]=min2;
				}
		double min2=999999999;
		for(i=0;i<1805;i++)
			if(d[n-1][m-1][i]<min2&&d[n-1][m-1][i]!=-1)
				min2=d[n-1][m-1][i];
		cout<<"Case #"<<i2+1<<": ";
		cout<<min2*(n+m-1)<<endl;
	}
	return 0;
}
