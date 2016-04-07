#include<stdio.h>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define rep(i,s,t) for(int i=s;i<t;i++)
typedef unsigned long long ull;

const ull B1=10000007;
const ull B2=100000007;

multiset<ull>S;
int n,m,t,p,q,ans;
char s[1001][1001],a[101][51][51];
ull tmp[1001][1001],ttmp[1001][1001];

inline ull getHash1(char a[51][51]){
	ull x,y=0;
	rep(i,0,p){
		x=0;
		rep(j,0,q){
			x=x*B1+a[i][j];
		}
		y=y*B2+x;
	}
	return y;
}

inline void getHash2(char s[1001][1001]){
	ull t=1;
	rep(i,0,q) t*=B1;
	rep(i,0,n){
		ull a=0;
		rep(j,0,q) a=a*B1+s[i][j];
		tmp[i][q-1]=a;
		rep(j,q,m){
			tmp[i][j]=tmp[i][j-1]*B1-s[i][j-q]*t+s[i][j];
		}
	}
	t=1;
	rep(i,0,p) t*=B2;
	rep(i,q-1,m){
		ull a=0;
		rep(j,0,p) a=a*B2+tmp[j][i];
		ttmp[p-1][i]=a;
		S.erase(a);
		rep(j,p,n){
			ttmp[j][i]=ttmp[j-1][i]*B2-tmp[j-p][i]*t+tmp[j][i];
			S.erase(ttmp[j][i]);
		}
	}
}
int main(){
	int ca=1;
	while(scanf("%d%d%d%d%d",&n,&m,&t,&p,&q),n||m||t||p||q){
		S.clear();
		rep(i,0,n) scanf("%s",s[i]);
		rep(i,0,t) rep(j,0,p) scanf("%s",a[i][j]);
		rep(i,0,t){
			S.insert(getHash1(a[i]));
		}
		ans=0;getHash2(s);
		printf("Case %d: %d\n",ca++,t-S.size());
	}
	return 0;
}
