#include <bits/stdc++.h>

using namespace std;

const long double pi = acos(-1);

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        double n;
        cin >> n;
        n = 2 * n;
        long double r = 1. / (2 * sin(pi / (2 * n) ));
        long double c = 2 * r;
        long double ans = sqrt(c * c - 1);
        cout.precision(10);
        cout << fixed << r << " " << ans << "\n";
    }
    return 0;
}

