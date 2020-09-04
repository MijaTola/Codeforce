#include <bits/stdc++.h>

using namespace std;

int l[200010];
int main() {

    int n,k;
    cin >> n >> k;

    vector<int> v(n), b, c;

    for (int &x: v)
        cin >> x;

    b = c = v;

    sort(v.begin(), v.end());

    if(k == 1) cout << v[0] << "\n";
    else if(k >= 3) cout << v[n - 1] << "\n";
    else if(k == 2) {
        int mn = 1e9;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, b[i]);
            b[i] = mn;
        }
        mn = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, c[i]);
            c[i] = mn;
        }
        int ans = -1e9;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, max(b[i], c[i + 1]));
        }
        cout << ans << "\n";
    }

    return 0;
}

