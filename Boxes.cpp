#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

static const int MOD=1000000007;



#define N 8
#define S 900000

const int inf=0x3f3f3f3f;

int f[N][S];
int pos[N], top[N], val[N];

inline int hash_encode(int *pos, const int n){
	int buff=0;
	for(int i=0; i<n; i++){
		buff*=n;
		buff+=pos[i];
	}
	return buff;
}

inline void hash_decode(int *pos, const int n, int code)
{
	for(int i=n-1; i>=0; i--)
    {
		pos[i]=code%n;
		code/=n;
	}
}

void prepare(const int n)
{
	for(int i=0; i<n; i++)pos[i]=i;
	int code=hash_encode(pos, n);
	f[n][code]=0;
	queue<int> que;
	while(!que.empty())que.pop();
	que.push(code);
	for(;!que.empty();que.pop()){
		hash_decode(pos, n, que.front());
		int w=f[n][que.front()]+1;
		for(int i=0; i<n; i++)top[i]=inf;
		for(int i=0; i<n; i++)
        {
            if(top[pos[i]]>i)top[pos[i]]=i;
        }
        //cout<<que.front()<<" ";
		for(int i=0; i<n; i++){
			int k=top[i];
			if(top[i]==inf)continue;
			if(i>0 && top[i]<top[i-1]){
				pos[k]--;
				code=hash_encode(pos, n);
				pos[k]++;
				if(f[n][code]==inf){
					f[n][code]=w;
					//cout<<w<<" ";
					que.push(code);
				}
			}
			if(i<n-1 && top[i]<top[i+1]){
				pos[k]++;
				code=hash_encode(pos, n);
				pos[k]--;
				if(f[n][code]==inf){
					f[n][code]=w;
					que.push(code);
				}
			}
		}
	}
}
bool compare(int x, int y)
{
    	return val[x]<val[y];
}
int main(){
	memset(f, 0x3f, sizeof(f));
	for(int i=1; i<8; i++)prepare(i);
	int T;scanf("%d", &T);
	while(T--){
		int n;scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d", &val[i]);
			pos[i]=i;
		}
		sort(pos, pos+n, compare);
		if(f[n][hash_encode(pos, n)]<inf){
			printf("%d\n", f[n][hash_encode(pos, n)]);
		}else printf("-1\n");
	}
	return 0;
}
