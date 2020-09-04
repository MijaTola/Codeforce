#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int x; 
        cin >> x;
        long long ans = 0;
        
        while(x >= 10) {
            int dv = x / 10;
            ans += dv * 10;
            x %= 10;
            x += dv;
        }
        ans += x;
        cout << ans << "\n";
    }
    return 0;
}

