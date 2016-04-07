#include<bits/stdc++.h>
using namespace std;
int h, w;
char pol[600][600];
int d1[600][600], d2[600][600], q, lvx, lvy, pnx, pny;
int main()
{
    cin >> h >> w;
    for (int i = 0; i <= h; i++)
    {
        pol[i][0] = pol[i][w + 1] = '#';
    }
    for (int i = 0; i <= 2; i++)
    {
        pol[0][i] = pol[h + 1][i] = '#';
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> pol[i][j];
            if (pol[i][j] == '.' && pol[i][j - 1] == '.')
            {
                d1[i][j] = d1[i][j - 1] + 1;
            }
            else
            {
                d1[i][j] = d1[i][j - 1];
            }
            if (pol[i][j] == '.' && pol[i - 1][j] == '.')
            {
                d2[i][j] = d2[i - 1][j] + 1;
            }
            else
            {
                d2[i][j] = d2[i - 1][j];
            }
        }
    }
    cin >> q;
    int ans = 0;
    for (int yht = 0; yht < q; yht++)
    {
        ans = 0;
        cin >> lvy >> lvx >> pny >> pnx;
        for (int i = lvy; i <= pny; i++)
        {
            ans += (d1[i][pnx] - d1[i][lvx]);
        }
        for (int i = lvx; i <= pnx; i++)
        {
            ans += (d2[pny][i] - d2[lvy][i]);
        }
        cout << ans << endl;
    }
}
