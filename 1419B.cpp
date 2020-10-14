#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;


    while(t--) {
        long long x;
        cin >> x;
        
        long long p = 2;
        int ans = 0;

        auto get = [&](long long z) {
            return z * (z + 1) / 2;
        };

        while(x >= get(p - 1)) {
            ans++;
            x -= get(p - 1);
            p <<= 1LL;
        }

        cout << ans << "\n";
    }
    return 0;
}

