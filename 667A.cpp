#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main() {
    double d,h,v,e;
    cin >> d >> h >> v >> e;

    double ar = (pi * (d / 2) * (d / 2));
    double lvl = v / ar;
    
    double a = -1, b = 10000 + 10;
    for (int i = 0; i < 100; ++i) {
        double mid = (a + b) / 2;
        if(e * mid + h <= lvl * mid) b = mid;
        else a = mid;
    }
    if(b == 10000 + 10) return cout << "NO\n",0;
    cout << "YES\n";
    cout.precision(10);
    cout << fixed << b << "\n";
    return 0;
}

