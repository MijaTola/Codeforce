#include <bits/stdc++.h>

using namespace std;

int n,m;

int main() {
 
    cin >> n >> m;

    int c[n + 1][m + 1];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    int ans = 0;

    for (int j = 0; j < m; ++j) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            if(c[i][j] % m == j) {
                int pos = c[i][j] / m;
                if(pos < n)
                    v[(i - pos + n) % n]++;
            }
        }
        int mx = 1e9;

        for (int i = 0; i < n; ++i)
            mx = min(mx, n - v[i] + i);

        ans += mx;
    }
    
    cout << ans << "\n";
    return 0;
}

