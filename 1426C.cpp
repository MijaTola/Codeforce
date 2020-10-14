#include <bits/stdc++.h>

using namespace std;

int m;

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        cin >> m;

        int c = sqrt(m);

        int ans = 1e9;
        for (int i = max(c - 10000, 1); i <= c + 10000; ++i) {
            int cur = (i - 1) + (m - 1) / i;
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}

