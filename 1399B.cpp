#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        int da = 1e9 + 2;
        int db = 1e9 + 2;

        for (int &x: a) {
            cin >> x;
            da = min(da, x);
        }

        for (int &x: b) {
            cin >> x;
            db = min(db, x);
        }

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int dfa = a[i] - da;
            int dfb = b[i] - db;
            
            int mn = min(dfa,dfb);
            ans += mn;
            dfa -= mn;
            dfb -= mn;
            ans += dfa;
            ans += dfb;
        }
        cout << ans << "\n";
    }
    return 0;
}

