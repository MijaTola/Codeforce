#include <bits/stdc++.h>

using namespace std;

long long dis(int x, int y, int a, int b) {
    return (x - a) * (x - a) + (y - b) * (y - b);
}

int main() {
    long long a,b;
    cin >> a >> b;
    long long c = a * a + b * b;

    for (long long x = 1; x < a; ++x) {
        long long y = a * a - x * x;
        double sy = sqrt(1.*y);
        if(sy != (int)sy) continue;
        for (long long dx = 1; dx < b; ++dx) {
            long long dy = b * b - dx * dx;
            double sdy = sqrt(1.*dy);
            if(sdy != (int)sdy) continue;
            if(c == dis(x,sy,-dx,sdy) and x != -dx and sy != sdy) {
                cout << "YES\n";
                cout << x << " " << sy << "\n";
                cout << -dx << " " << sdy << "\n";
                cout << "0 0\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}

