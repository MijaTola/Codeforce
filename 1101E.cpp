#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int h = 0, w = 0;
    while(t--) {
        char c;
        int x,y;
        cin >> c >> x >> y;
        int mx = max(y, x);
        int mn = min(y, x);
        if(c == '+') {
            h = max(h,mx);
            w = max(w, mn);
        } else puts((mx >= h and mn >= w) ? "YES": "NO");
    }
    return 0;
}

