#include <bits/stdc++.h>

using namespace std;


int main() {
    

    int t;
    cin >> t;
    while(t--) {
        int c,m,x;
        cin >> c >> m >> x;
        long long ans = min(c, min(m,x));
        c -= ans, m -= ans, x -= ans;
        
        if(!c or !m) {
            cout << ans << "\n";
            continue;
        }
        
        int dif = abs(c - m);
        dif = min(dif, min(c,m));
        ans += dif;
        if(c > m) m -= dif, c = m;
        else c -= dif, m = c;
        
        if(c < 2 and m < 3) {
            cout << ans << "\n";
            continue;
        }
        int cur = (c - 2) / 3;
        ans += (cur * 2 + 1) + ((c - 2) % 3 != 0);
        cout << ans << "\n";
    }
    return 0;
}

