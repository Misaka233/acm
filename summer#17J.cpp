#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t,a,b,c;
  scanf("%d",&t);
  for(int cas=1;cas<=t;cas++)
  {
    scanf("%d%d%d",&a,&b,&c);
    double r;
    if (c==10||c==100||c==1000)
              if (b==a||b/10==a||b/100==a||b/1000==a||b*10==a||b*100==a||b*1000==a) r=1;
              else r=0;
    else
      if (c==1) if (b==a||b/10==a||b/100==a||b/1000==a) r=1;
            else r=0;
     else r=log10((double)(a+1)/double(a));
    printf("Case #%d: %.5lf\n",cas,r);
  }
  return 0;
}
