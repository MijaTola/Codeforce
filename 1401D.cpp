#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[100100];
int depth[100100];
vector<long long> e;
const int mod = 1e9 + 7;

void dfs(int u, int p = -1) {
    depth[u] = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, u);
        depth[u] += depth[v];
        long long abajo = depth[v];
        long long arriba = n - depth[v];
        e.push_back(1LL * arriba * abajo);
    }

}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {

        cin >> n;

        for (int i = 1; i <= n + 10; ++i) {
            G[i].clear();
            depth[i] = 0;
        }

        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        dfs(1);

        int m;
        cin >> m;

        vector<long long> f;

        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            f.push_back(x);
        }

        sort(f.begin(), f.end());
        sort(e.begin(), e.end());


        while(f.size() > e.size()) {
            long long x = f.back();
            f.pop_back();
            f.back() *= x;
            f.back() %= mod;
        }

        long long ans = 0;
        while(e.size() and f.size()) {
            ans += (e.back() * f.back()) % mod;
            ans %= mod;
            e.pop_back();
            f.pop_back();
        }

        while(e.size()) {
            ans += e.back();
            ans %= mod;
            e.pop_back();
        }

        cout << ans << "\n";

    }

    return 0;
}
