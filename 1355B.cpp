#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int &x: v)
            cin >> x;

        sort(v.begin(), v.end());
        
        int ans = 0;
        int cur = 0;
        int mx = 0;

        for (int i = 0; i < n; ++i) {
            mx = max(mx, v[i]);
            cur++;
            if(cur >= mx) {
                cur = 0;
                mx = 0;
                ans++;
            }
        }

        cout << ans << "\n";

    }
    return 0;
}

