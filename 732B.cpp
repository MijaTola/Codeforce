#include <bits/stdc++.h>

using namespace std;

int v[510];
int main() {
    
    int n,k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    v[0] = v[n + 1] = k;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int d = max(0, k - (v[i] + v[i - 1]));
        ans += d;
        v[i] += d;
    }

    cout << ans << "\n";

    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}

