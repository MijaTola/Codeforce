#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int l,r;
        long long m;
        cin >> l >> r >> m;

        bool flag = 0;
        for (int i = l; i <= r; ++i) {
            long long z = m / i;
            for (long long p = z - 25; p <= z + 25; ++p) {
                long long an = p * i;
                long long left = m - an;
                long long b = r;
                long long c = b - left;

                if(left < 0) {
                    b = l;
                    c = l - left;
                }

                if(l <= i and i <= r and l <= b and b <= r 
                        and l <= c and c <= r and p > 0 and m == i * p + b - c) {
                    cout << i << " " << b << " " << c << "\n";
                    flag = 1;
                    goto fin;
                }
            }
        }
        fin:
        assert(flag);
    }
    return 0;
}

