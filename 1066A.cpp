#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int L,v,l,r;
        cin >> L >> v >> l >> r;
        long long ans = L / v;
        long long dl = (l - 1) / v;
        long long dr = r / v;
        ans = ans - dr + dl;
        cout << ans << "\n";
    }
    return 0;
}

