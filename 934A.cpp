#include <bits/stdc++.h>

using namespace std;

int a[55];
int b[55];
int main () {
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long mul = LLONG_MIN;
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            for (int k = 0; k < m; ++k) 
                mul = max(mul, (long long)a[j] * b[k]);
        }
        ans = min(ans, mul);
    }
    cout << ans << "\n";
    return 0;
}
