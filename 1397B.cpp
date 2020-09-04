#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &x: v)
        cin >> x;

    sort(v.begin(), v.end());
    long long ans = 0;

    ans = 1e18;
    for (int i = 1; i <= 1000000; ++i) {
        long long p = 1;
        long long cur = 0;
        int j= 0;
        for (; j < n and p < 1e18 / i; ++j, p *= i) {
            cur += abs(v[j] - p);
            if(p > 1e18 / i) break;
        }
        if(j == n) ans = min(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}

