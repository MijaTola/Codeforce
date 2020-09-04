#include <bits/stdc++.h>

using namespace std;

int n;
map<int, long long> mp;

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        mp[x - i] += x;
    }

    long long ans = 0;
    for (auto p: mp)
        ans = max(ans, p.second);
    cout << ans << "\n";
    return 0;
}

