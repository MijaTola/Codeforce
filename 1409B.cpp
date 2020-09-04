#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while(t--) {
        long long a,b,x,y,n;

        cin >> a >> b >> x >> y >> n;

        auto get = [] (long long a, long long b, long long x, long long y, long long n) {
            long long df = a - x;
            long long mn = min(df, n);
            a -= mn;
            n -= mn;
            //cout << a << " " << x << "\n";
            long long z = b - n;
            b = max(z, y);
            return a * b;
        };

        cout << min(get(a,b,x,y,n), get(b,a,y,x,n)) << "\n";

    }
    return 0;
}

