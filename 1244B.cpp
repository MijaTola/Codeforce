#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = n;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '0') continue;
            int u = i + 1;
            int d = n - i;
            ans = max(ans, u + d);
            ans = max(ans, 2 * u);
            ans = max(ans, 2 * d);
        }
        cout << ans << "\n";
    }
    return 0;
}

