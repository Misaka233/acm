#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
int main()
{
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&m,&n);
        cas++;
        cout<<"Case #"<<cas<<": ";
        if(m == 1)
        {
            for(int i = 0;i < n;i++)printf("a");
            cout<<endl;
            continue;
        }
        if(m >= 3)
        {
            int x = 0;
            for(int i = 0;i < n;i++)
            {
                printf("%c",x + 'a');
                x = (x + 1)%3;
            }
            cout<<endl;
            continue;
        }
        if(n == 1)printf("a");
        else if(n == 2)printf("ab");
        else if(n == 3)printf("aab");
        else if(n == 4)printf("aabb");
        else if(n == 5)printf("aaaba");
        else if(n == 6)printf("aaabab");
        else if(n == 7)printf("aaababb");
        else if(n == 8)printf("aaababbb");
        else if(n == 9)printf("aaaababba");
        else{
            printf("aaaa");
             n -= 4;
            while(n >= 6)
             {
                 printf("babbaa");
                 n -= 6;
             }
                if(n == 1)printf("a");
                else if(n == 2)printf("aa");
                else if(n == 3)printf("bab");
                else if(n == 4)printf("babb");
                else if(n == 5)printf("babba");
                    }
               cout<<endl;
        }


    }

