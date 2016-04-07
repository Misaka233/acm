#include<iostream>
using namespace std;
int main()
{
	int a[2];
	cin>>a[0]>>a[1];
	for (int i=a[0];i<=a[1];i++)
	{
		for (int n=2;n<=i/2;n++)
		{
			if (i%n==0)
			{
				goto A;
			}
		}
		cout<<i<<" ";
		A:;
	}
}
