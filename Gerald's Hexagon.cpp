#include<bits/stdc++.h>
using namespace std;
int s[1010];
int main()
{
    for(int i=1;i<=6;i++)
        scanf("%d",&s[i]);
    cout<<(s[1]+s[2]+s[3])*(s[1]+s[2]+s[3])-s[1]*s[1]-s[3]*s[3]-s[5]*s[5];
  return 0;
}
