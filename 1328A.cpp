#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int l,r;
        cin >> l >> r;

        if(l <= r) {
            cout << (r - l) << "\n";
            continue;
        }

        long long a = -1, b = 1e9;

        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(mid * r >= l) b = mid;
            else a = mid;
        }
        long long cur = b * r;
        cout << cur - l << "\n";
    }
    return 0;
}

