#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    vector<long long> a(n), t(n), b(n), c(n);

    for (auto &x: a)
        cin >> x;

    for (auto &x: t)
        cin >> x;
    
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        if(t[i]) {
            b[i] = a[i];
            total += b[i];
        }
        c[i] = a[i];
    }

    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }

    long long ans = total;
    
    for (int i = 0; i < n - k + 1; ++i) {
        int l = i;
        int r = min(n, i + k - 1);
        int da = c[r];
        int db = b[r];
        if(l - 1 >= 0) {
            da -= c[l - 1];
            db -= b[l - 1];
        }
        ans = max(ans, da + (total - db));
    }

    cout << ans << "\n";

    return 0;
}

