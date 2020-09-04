#include <bits/stdc++.h>

using namespace std;

int v[300010];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    reverse(v, v + n);
    long long total = 0;
    for (int i = n - 1; i >= 0; i--) {
        total += v[i];
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << total - v[x - 1] << "\n";
    }
    return 0;
}

