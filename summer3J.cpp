#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int n,m;
int v[1000];
int a[5005];
int b[1000005];
int main()
{
    v['a']=v['b']=v['c']=2;
    v['d']=v['e']=v['f']=3;
    v['g']=v['h']=v['i']=4;
    v['j']=v['k']=v['l']=5;
    v['m']=v['n']=v['o']=6;
    v['p']=v['q']=v['r']=v['s']=7;
    v['t']=v['u']=v['v']=8;
    v['w']=v['x']=v['y']=v['z']=9;
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;
            int number=0;
            for(int j=0;j<s.size();j++)
            {
                number=number*10+v[s[j]];
            }
            b[number]++;
        }
        for(int i=0;i<n;i++)
        {
            cout<<b[a[i]]<<endl;
        }
    }
    return 0;
}
