#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t; cin >> t;
    while(t--) {
        int n,x,y,d;
        cin >> n >> x >> y >> d;
        
        if(abs(y - x) % d == 0) {
            cout << abs(y - x) / d << "\n";
            continue;
        }
        
        int ans = 1e9;

        if(abs(y - 1) % d == 0) {
            ans = min(ans, abs(y - 1) / d + (x / d) + (x % d != 0));
        }

        if(abs(y - n) % d == 0) {
            ans = min(ans, abs(y - n) / d + abs(n - x) / d + ((n - x) % d != 0));
        }

        if(ans == 1e9) cout << "-1\n";
        else cout << ans << "\n";
    }

    

    return 0;
}

