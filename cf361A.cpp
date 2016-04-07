
 #include <bits/stdc++.h>
using namespace std;
int n,a,m,c;
int main()
{
   scanf("%d %d",&n,&m);
   if(n==1){cout<<1<<endl;return 0;}


   if(n==2)
   {
       if(m==1){cout<<2<<endl;return 0;}
       if(m==2){cout<<1<<endl;return 0;}
   }
   if(n==3&&m==2) {cout<<1<<endl;return 0;}
   if(m-1>=n-m) {cout<<m-1<<endl;return 0;}
   if(m-1<n-m) {cout<<m+1<<endl;return 0;}
}
