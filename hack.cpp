#include <bits/stdc++.h>
using namespace std;

int main() {
    
    for (double i = 1; i <= 50; ++i) {
        for (double j = 1; j <= 50; ++j) {
            for (double k = 1; k <= 50; ++k) {
                for (double l = 1; l <= 50; ++l) {
                    long double x = i / j;
                    long double y = k / l;
                    if(abs(x - y) <= 1e-30 and abs(x - y) > 1e-9) {
                        cout.precision(30);
                        cout << i << " " << j << " a\n";
                        cout << k << " " << l << " b\n";
                        cout << x << " da\n";
                        cout << y << " db\n";
                        cout << "\n";
                    }
                }
            }
        }
    }
}
