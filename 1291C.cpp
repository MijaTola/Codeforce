#include <bits/stdc++.h>

using namespace std;

int n,t,m,k,x;

int main() {

    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) 
            cin >> v[i];
        
        vector<int> b;

        int a = 0;
        for (int i = 0; i < m; ++i) {
            b.push_back(max(v[i], v[i + n - m]));
            a = max(a, b.back());
        }

        int ans = 0;

        for (int i = 0; i <= k; ++i) {
            int mn = INT_MAX;
            for (int j = 0; j < m - k; ++j) {
                mn = min(mn, b[i + j]);
                //cout << mn << "\n";
            }
            ans = max(ans, mn);
        }
        cout << min(ans,a) << "\n";
    }
    return 0;
}

