#include <bits/stdc++.h>

using namespace std;

int v[110];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        ans += abs(v[i] - v[i - 1]);
    }

    cout << ans << "\n";
    return 0;
}

