#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> v(n), w(k);

        for (int &x: v)
            cin >> x;
        

        for (int &x: w)
            cin >> x;
        
        sort(w.rbegin(), w.rend());
        sort(v.begin(), v.end());
    
        long long ans = 0;
        
        vector<int> b;
        for (int i = n - 1, j = k; j > 0; j--, i--) {
            b.push_back(v[i]);
        }
        
        sort(b.begin(), b.end());

        for (int i = 0, p = 0; i < k; ++i) {
            if(w[i] - 1 > 0) b[i] += v[p];
            else b[i] += b[i];
            p += (w[i] - 1);
        }
        
        for (int x: b)
            ans += x;
        cout << ans << "\n";

    }
    return 0;
}

