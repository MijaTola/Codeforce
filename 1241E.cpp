#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<pair<int,int> > G[500010];

long long dp[500010][2];
long long dfs(int u, int parent, int flag) {
    vector<pair<int,pair<int,int> > > v;
    long long &ans = dp[u][flag];
    if(ans != -1) return ans;
    ans = 0;
    for (auto p: G[u]) {
        if(parent == p.first) continue;
        v.push_back({dfs(p.first, u, 1) + p.second - dfs(p.first, u, 0), {p.first, p.second}});
    }
    
    sort(v.rbegin(), v.rend());
    int dk = k - flag;
    for (auto p: v) {
        if(p.first >= 0 and dk) ans += dfs(p.second.first, u, 1) + p.second.second, dk--;
        else ans += dfs(p.second.first, u, 0);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        vector<pair<int,pair<int,int> > > e;
        map<int,int> v;
        cin >> n >> k;
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = dp[i][1] = -1;
            G[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int x,y,w;
            cin >> x >> y >> w;
            G[x].push_back({y,w});
            G[y].push_back({x,w});
        }

        cout << dfs(1,1,0) << "\n";      
    }
    return 0;
}

