#include <iostream>
#include <fstream>
#include<cstdlib>
using namespace std;

int main()
{
  fstream fso("data.txt", ios::out);

  int i;
  for(i = 0; i < 100; ++i)
    fso << rand() << ' ';
  fso.close();

  fstream fsi("data.txt", ios::in);
  int x[100];
  for(i = 0; i < 100; ++i)
    fsi >> x[i];

  int j;
  for(i = 0; i < 100; ++i)
    for(j = 99; j > i; --j)
      if(x[j - 1] > x[j])
      {
        int t = x[j];
        x[j] = x[j - 1];
        x[j - 1] = t;
      }
  for(i = 0; i < 100; ++i)
    cout << x[i] << '\t';

  return 0;
}
