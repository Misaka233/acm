#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int l = s.length();
        for (int i = 0; i < l; i++) {

            string a = s.substr(i, 4);
            if (a == "iPod" || a == "iPad") {
                printf("MAI MAI MAI!\n");
            }
            else if (a == "Sony") {
                printf("SONY DAFA IS GOOD!\n");
            }

            string b = s.substr(i, 5);
            if (b == "Apple") {
                printf("MAI MAI MAI!\n");
            }

            string c = s.substr(i, 6);
            if (c == "iPhone") {
                printf("MAI MAI MAI!\n");
            }
        }
    }
    return 0;
}
