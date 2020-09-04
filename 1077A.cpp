#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        long long a,b,k;
        cin >> a >> b >> k;
        long long ma = (k + 1) / 2;
        long long mb = k / 2;
        cout << a * ma - b * mb << "\n";
    }
    return 0;
}

