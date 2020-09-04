#include <bits/stdc++.h>

using namespace std;

int v[110];

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        memset(v, 0, sizeof v);
        int n;
        cin >> n;
    
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[x]++;
        }

        int ans = 0;
        for (int i = 2; i <= 100; ++i) {
            int cur = 0;
            set<pair<int,int> > s;
            for (int j = 1; j <= 50; ++j) {
                int k = i - j;
                if(k <= 0 or k > 50) continue;
                if(s.count({min(j,k), max(j,k)})) continue;
                s.insert({min(j,k), max(j,k)});
                if(j != k) cur += min(v[j], v[k]);
                else cur += v[j] / 2;
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}

