#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int s,n;
        cin >> s >> n;
        
        if(s <= n) {
            if(s & 1 and s > 1) cout << "2\n";
            else cout << "1\n";
        } else {
            if(n & 1) n--;
            int ans = 0;
            if(s & 1) s--, ans++;
            ans += s / n;
            s %= n;
            if(s > 0) ans++;
            cout << ans << "\n";
        }


    }
    return 0;
}

