#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x;
        cin >> x;
        long long ans2 = (1LL << (__builtin_popcount(x)));
        cout << ans2 << "\n";
    }
    return 0;
}

