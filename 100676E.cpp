#include <bits/stdc++.h>

using namespace std;

long long v[10010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        memset(v, 0, sizeof v);
        int n,x;
        cin >> n;
        for (int i = 0; i < n; ++i)  {
            cin >> x;
            v[x]++;
        }
        long long ans = 0;

        for (int i = 1; i < 10010; ++i) {
            ans += (v[i] * (v[i] - 1)) / 2;
            v[i] += v[i - 1];
        }

        for (int i = 1; i <= 10000; ++i) {
            int l = max(1, i - 31);
            int cur = v[i - 1] - v[l - 1];
            int total = v[i] - v[i - 1];
            ans += total * cur;
        }
        cout << ans << "\n";
    }
    return 0;
}
