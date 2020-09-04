#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int &x: v)
            cin >> x;

        int last = v[0];

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if(last > v[i]) {
                int df = last - v[i];
                int bit = 31;
                while(!(df & (1 << bit)) and bit >= 0) bit--;
                ans = max(ans, bit + 1);
            } else {
                last = v[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

