#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int i;
double k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
        scanf("%lf",&k);
		k=0.5-k;
		for(i=0;i<20000;i++)
		{
			k*=2;
			if(k>=1-1e-10)
            {
                break;
            }
		}
		if(k!=1)
			printf("%d\n",i*4);
		else
            printf("-1\n");
	}
	return 0;
}


