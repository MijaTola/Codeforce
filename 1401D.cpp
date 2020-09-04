#include <bits/stdc++.h>

using namespace std;

int n;
long long d[200010];
const int mod = 1e9 + 7;
vector<long long> G[200010],b;

int dfs(int u, int p = -1) {
    int ans = 1;
    for (int v: G[u]) {
        if(v != p) {
            int val = dfs(v,u);
            b.push_back(1LL * (n - val) * val);
            ans += val;
        }
    }
    return ans;
}


int main() {
    
    int t;
    cin >> t;

    while(t--) {
        b.clear();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            d[i] = 0;
        }
        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >>  x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int m;
        cin >> m;
        vector<long long> v(m);

        for (auto &x: v)
            cin >> x;

        
        dfs(1);

        sort(v.begin(), v.end());
        sort(b.begin(), b.end());

        long long ans = 0;
        while(v.size() and b.size()) {
            ans += (1LL * v.back() * b.back()) % mod;
            ans %= mod;
            v.pop_back();
            b.pop_back();
        }

        while(b.size()) {
            ans += b.back();
            ans %= mod;
            b.pop_back();
        }
        cout << ans << "\n";

    }
    return 0;
}

