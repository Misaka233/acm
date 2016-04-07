#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int a_length=a.size();
    int b_length=b.size();
    int aa=a_length,bb=b_length;
    for(int i=0;i<a_length;i++)
    {
        if(a[i]=='0')
            aa--;
        else
            break;
    }
    for(int i=0;i<b_length;i++)
    {
        if(b[i]=='0')
            bb--;
        else
            break;
    }
    if(aa>bb)
        cout<<">"<<endl;
    else if(aa<bb)
        cout<<"<"<<endl;
    else if(aa==0&&aa==bb)
    {
        cout<<"="<<endl;
    }
    else if(aa==1&&aa==bb)
    {
        if(a[a_length-1]<b[b_length-1])
            cout<<"<"<<endl;
        else if(a[a_length-1]>b[b_length-1])
            cout<<">"<<endl;
        else if(a[a_length-1]=b[b_length-1])
            cout<<"="<<endl;
    }
    else
    {
        int i,j,flag=0;
        for(i=a_length-aa,j=b_length-bb;i<a_length;i++,j++)
        {
            if(a[i]<b[j])
            {
                cout<<"<"<<endl;
                flag=1;
                break;
            }
            if(a[i]>b[j])
            {
                cout<<">"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"="<<endl;
    }

    return 0;
}
