#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string ans = "";
        int sz = 4 * n;
        int cur = 0;

        while(cur + 4 <= n) {
            cur += 4;
            ans += "8";
        }
        
        if(cur < n) {
            ans += "8";
            cur += 4;
        }

        while(cur + 4 <= sz) {
            ans += "9";
            cur += 4;
        }
        
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }

    return 0;
}

