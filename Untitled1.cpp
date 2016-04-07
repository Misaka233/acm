#include <iostream>
using namespace std;
const int maxn=100000000;
int a[maxn];
template <class T>
int quick2_sort(T a[],int low,int high)
{
	T temp=a[low];
	int pos=low;
	int i=low,j=high;
	while(i<j)
	{
		while(i<j && a[j]>temp)
			j--;
		if(i<j)
		{
			a[pos]=a[j];
			pos=j;
		}
		while(i<j && a[i]<temp)
			i++;
		if(i<j)
		{
			a[pos]=a[i];
			pos=i;
		}
	}
	a[pos]=temp;
	return pos;
}
template <class T>
T findkth(T a[],int n,int k)
{
	int low=0,high=n-1;
	while(1)
	{
		int pos=quick2_sort(a,low,high);
		if(pos==n-k)
			return a[pos];
		else if(pos<n-k)
		{
			low=pos+1;
			high=n-1;
		}
		else if(pos>n-k)
		{
			high=pos-1;
			low=0;
		}
	}
}

int main()
{

	int n,k;
	while(cin>>n>>k)
    {
        if(n==0&&k==0) return 0;
        for(int i=0;i<n;i++)
        {
            a[i]=i<<3;
        }
        cout<<findkth(a,n,k+1)<<endl;
    }
    return 0;
}




