#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
    
        for (int &x: v)
            cin >> x;

        sort(v.begin(), v.end());

        long long ans = 0;

        for (int i = 1; i < n; ++i) {
            
            int l = k - v[i];
            ans += l / v[0];
            v[i] += (l/v[0]) * v[0];

        }


        cout << ans << "\n";

    }
    return 0;
}

