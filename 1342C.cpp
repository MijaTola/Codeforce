#include <bits/stdc++.h>

using namespace std;

long long lcm;
unsigned long long bs(unsigned long long k) {
    unsigned long long a = -1, b = 1e15;
    while(b - a > 1) {
        unsigned long long mid = (a + b) / 2;
        if(mid * lcm > k) b = mid;
        else a = mid;
    }
    return b;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        long long a,b,q;
        cin >> a >> b >> q;

        if(a > b) swap(a, b);

        lcm = (a * b) / __gcd(a,b);
        long long d = lcm - b;
        while(q--) {
            long long l,r;
            cin >> l >> r;
            long long ini = (bs(l - 1)) * lcm - 1;
            long long fin = (bs(r)) * lcm - 1;
            auto f = [&] (long long x, auto right) {
                long long val = (right / d) * d;
                long long left = min(d, right - x);
                return val - left;
            };

            cout << fin << "\n";
            cout << f(r, fin)<< " "<<  f(l - 1, ini) << " ";
        }
        cout << "\n";

    }

    return 0;
}

