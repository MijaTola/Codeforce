#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    
    int t,x;
    string s;
    cin >> t;
    while(t--) {
        cin >> x >> s;
        
        long long ans = s.size();
        string cur = s;

        for (int i = 0; i < x; ++i) {
            long long u = cur[i] - '0';
            ans = ((i + 1) + (((ans - (i + 1) + mod) % mod) * u) % mod) % mod;
            int sz = cur.size();
            for (int j = 0; j < u - 1 and (int)cur.size() < x; ++j) 
                for (int k = i + 1; k < sz and (int)cur.size() < x; ++k) 
                    cur += cur[k];
        }

        cout << ans << "\n";
        
    }
    return 0;
}

