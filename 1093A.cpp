#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while(t--) {
        int ans = 0;
        int p = 7;
        int x; cin >> x;
        while(x > 0 and p >= 2) {
            if(x >= p) {
                x -= p;
                ans++;
            }else p--;
        }
        if(x) ans++;
        cout << ans << "\n";
    }
    return 0;
}

