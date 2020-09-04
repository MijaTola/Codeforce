#include <bits/stdc++.h>

using namespace std;

int v[1000010];
const int mod = 1e9 + 7;
int main() {

    int n;
    cin >> n;
    v[0] = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        vector<int> dv;
        for (int j = 1; j * j <= x; ++j) {
            if(x % j == 0) {
                dv.push_back(j);
                if(j != x / j) dv.push_back(x / j);
            }
        }

        sort(dv.rbegin(), dv.rend());

        for (int j = 0; j < (int)dv.size(); ++j) 
            v[dv[j]] = (v[dv[j]] + v[dv[j] - 1]) % mod;
        
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + v[i]) % mod;

    cout << ans << "\n";
    return 0;
}
