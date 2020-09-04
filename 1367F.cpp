#include <bits/stdc++.h>

using namespace std;
int main() {

    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;
        vector<int> v(n + 10);
        vector<vector<int> > G(n + 10);
        vector<pair<int,int> > b;

        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            b.push_back({v[i], i});
        }

        sort(b.begin(), b.end());

        map<pair<int,int>, int > mp;
        map<int,int> pos;
        
        int id = 1;
        for (int i = 0 ; i < n; ++i) {
            mp[b[i]] = i;
            if(!pos.count(b[i].first)) pos[b[i].first] = id++;
        }

        for (int i = 1; i <= n; ++i) {
            int val = pos[v[i]];
            G[val].push_back(i);
        }

        
        vector<int> dp(n + 20), dp2(n + 20);
        
        for (int i = n; i >= 1; --i) {
            int val = pos[v[i]];

            int p = upper_bound(G[val].begin(), G[val].end(), i) - G[val].begin();
            int nxt = n + 1;
            if(p >= 0 and p < (int)G[val].size()) nxt = G[val][p];

            dp[i] = max(dp[i], dp[nxt] + 1);

            p = upper_bound(G[val + 1].begin(), G[val + 1].end(), i) - G[val + 1].begin();
            nxt = n + 1;
            if(p >= 0 and p < (int)G[val + 1].size()) nxt = G[val + 1][p];
            dp[i] = max(dp[i], dp[nxt] + 1);
        }

        for (int i = 1; i <= n; ++i) {
            int val = pos[v[i]];
            int p = lower_bound(G[val].begin(), G[val].end(), i) - G[val].begin();
            p--;
            int nxt = 0;
            if(p >= 0 and p < (int)G[val].size()) nxt = G[val][p];
            dp2[i] = max(dp2[i], dp2[nxt] + 1);
            p = lower_bound(G[val - 1].begin(), G[val - 1].end(), i) - G[val - 1].begin();
            p--;
            nxt = 0;
            if(p >= 0 and p < (int)G[val - 1].size()) nxt = G[val - 1][p];
            dp2[i] = max(dp2[i], dp2[nxt] + 1);
        }

        int ans = 1e9;
        for (int i = 1; i <= n; ++i) {
            int cnt = dp2[i];
            int id = mp[make_pair(v[i], i)];
            int cur = id - cnt + 1;
            cnt = dp[i] - 1;
            cur += (n - id - 1) - cnt;
            ans = min(ans, cur);
        }
        cout << ans << "\n";

    }
    return 0;
}

