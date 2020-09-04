#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int h,m;
        cin >> h >> m;

        int total = h * 60 + m;
        int ans = 24 * 60 - total;
        
        cout << ans << "\n";
    }
    return 0;
}

