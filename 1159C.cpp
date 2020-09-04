#include <bits/stdc++.h>

using namespace std;

int n,m;
int b[100010];
int g[100010];
int a[100010];
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < m; ++i)
        cin >> g[i];
    

    sort(g, g + m);
    sort(b, b + n);
    reverse(b, b + n);
    for (int i = m - 1; i >= 0; i--) {
        a[i] = g[i];
        a[i] += a[i + 1];
    }
    int lim = m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(g, g + m, b[i]) - g;
        if(pos + 1 <= lim) {
            ans += a[pos + 1] - a[lim];
            cout << a[pos + 1] - a[lim] << "";
            ans += b[i];
            lim = pos + 1;
        } else {
            ans += b[i] * (m - pos);
        }
        
    }
    cout << ans << "\n";
    return 0;
}

