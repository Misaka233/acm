
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
multiset <int> s;
multiset <int> ::iterator it,mid;
char st[10];
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        s.clear();
        while(n--){
            scanf("%s%d",st,&x);
            if(st[0]=='a'){
                s.insert(x);
                if(s.size()==1)mid=s.begin();
                else if(s.size()%2==0&&*mid<=x)++mid;
                else if(s.size()%2==1&&*mid> x)--mid;
            }
            else if(st[0]=='r'){
                it=s.find(x);
                if(it==s.end()){
                    printf("Wrong!\n");
                    continue;
                }
                if(it != mid){
                    if(s.size()%2==0&&*mid<x)--mid;
                    else if(s.size()%2==1&&*mid>=x)++mid;
                }
                else {
                    if(s.size()%2==0)--mid;else ++mid;
                }
                s.erase(it);
                if(s.empty()){
                    printf("Empty!\n");
                    continue;
                }
            }
            if(s.size()%2==1){ printf("%d\n",*mid); }
            else {
                it=mid;
                it--;
                long long ans=(long long)*mid+(long long)*it;

                if(ans%2==0)printf("%lld\n",ans/2);
                else printf("%.1lf\n",(double)ans/2.0);
            }
        }
    }
    return 0;
}
