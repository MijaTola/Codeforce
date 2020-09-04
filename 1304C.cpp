#include <bits/stdc++.h>

using namespace std;

int main() {

    int te;
    cin >> te;

    while(te--) {
        int n,ini;
        cin >> n >> ini;
        
        int mn = ini, mx = ini, curT = 0;
        bool flag = 1;

        for (int i = 0; i < n; ++i) {
            int t, l,r;
            cin >> t >> l >> r;
            int dl = mn - (t - curT);
            int dr = mx - (t - curT);
            if(dl < l or dr > r) flag = 0;
            mn = max(l, dl);
            mx = max(r, dr);
        }
        puts(flag ? "YES": "NO");
    }
    return 0;
}

