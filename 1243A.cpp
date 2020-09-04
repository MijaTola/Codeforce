#include <bits/stdc++.h>

using namespace std;

int t;
int v[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v, v + n);
        reverse(v, v + n);
    
        int mn = 1e9;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            mn = min(mn , v[i]);
            ans = max(ans, min(i + 1, mn));
        }

        cout << ans << "\n";
    }
    return 0;
}

