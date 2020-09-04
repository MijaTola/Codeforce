#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> v(n);

    for (auto &x: v)
        cin >> x ;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, v[i]);
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            ans = max(ans, v[i] | v[j]);
            for (int k = 0; k < n; ++k) {
                if(i == j or j == k or i == k) continue;
                long long a = v[i];
                long long b = v[j];
                long long c = v[k];
                ans = max(ans, (a | b) | c);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

