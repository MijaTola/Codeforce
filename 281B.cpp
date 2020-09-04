#include <bits/stddc++.h>
using namespace std;
 
int main() {
    int x, y, n, a, b;
        long double mn = 1e9, t;
        cin >> x >> y>>n;;
        t= x / (long double) y;
        ++n;
        for (int i = 1; i < n; ++i) {
                if (abs(t- floor(t* i) / i) < mn) {
                        b = i;
                        a = floor(t* i);
                        mn = abs(t- floor(t* i) / i);
                }
                if (abs(t- ceil(t * i) / i) < mn) {
                        b = i;
                        a = ceil(t* i);
                        mn = abs(t- ceil(t* i) / i);
                }
        }
        cout << a << "/" << b;
        return 0;
}