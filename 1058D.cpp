#include <bits/stdc++.h>

using namespace std;

int main() {

    double n,m,k;
    cin >> n >> m >> k;
    double a = n * m / k;
    double h = 2 * a / n;
    double b = 2 * a / m;
    if(h > m and b > n) return cout << "NO\n",0;
    cout.precision(11);
    cout << fixed;
    for (int i = n; i >= b; i--) {
        double hh =  2 * a / i;
        if(hh == (int)hh) {
            cout << "YES\n";
            cout << "0 0\n";
            cout << i << " 0\n";
            cout << "0 " << (int)hh << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

