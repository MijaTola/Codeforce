#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        
        vector<int> v(n), vis(n + 10, 0);

        for (int &x: v)
            cin >> x;
        
        
        int ans = 0;

        auto check = [&] () {
            for (int i = 0; i < n; ++i)
                if(v[i] > 0) return 1;
            return 0;
        };

        bool can = 1;
        while(check()) {
            
            int last = -1;
            int cnt = 0;
            
            int val = -1;
            vector<int> b = v;
            for (int i = 0; i < n and cnt <= k; ++i) {
                if(v[i] >= 0) {
                    if(last != v[i] and cnt < k) {
                        cnt++;
                        val = v[i];
                    }
                    last = v[i];
                    v[i] -= val;
                }
            }
        
            if(v == b) {
                can = 0;
                break;
            }

            ans++;
        }

        if(can) cout << ans << "\n";
        else cout << "-1\n";


    }
    return 0;
}

