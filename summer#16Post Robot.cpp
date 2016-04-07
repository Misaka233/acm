#include <bits/stdc++.h>
using namespace std;
 int main()
 {
     string s;
     while(cin>>s)
     {
         for (int i = 0; i<s.size(); i++)
         {
             string ss=s.substr(i,4);
             if(ss=="iPod"||ss=="iPad")
                {cout<<"MAI MAI MAI!"<<endl;}
             else if(ss=="Sony")
                {cout<<"SONY DAFA IS GOOD!"<<endl;}
             string sss=s.substr(i,5);
             if(sss=="Apple")
                 {cout<<"MAI MAI MAI!"<<endl;}
             string sox=s.substr(i,6);
             if(sox=="iPhone")
                {cout<<"MAI MAI MAI!"<<endl;}
         }

     }
      return 0;
 }
