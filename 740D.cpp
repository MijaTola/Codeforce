#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000010];
int ans[1000010];
int cnt[1000010];
vector<pair<long long,int> > G[1000010], path;

int bs(int ai) {
    int a = -1, b = path.size();
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(path[path.size() - 1].first - path[mid].first <= ai) b = mid;
        else a = mid;
    }
    return path[b].second;
}

void dfs(int u) {
    int val = bs(a[u]);
    cnt[u]++;
    cnt[val]--;
    for (auto p: G[u]) {
        int v = p.first;
        int w = p.second;
        path.push_back({path.back().first + w, u});
        dfs(v);
        path.pop_back();
    }
}

int f(int u) {
    int cur = cnt[u];
    for (auto p: G[u]) {
        int v = p.first;
        cur += f(v);
    }
    ans[u] = cur;
    return cur;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 2; i <= n; ++i) {
        int p,w;
        cin >> p >> w;
        G[p].push_back({i,w});
    }
    path.push_back({0,0});
    dfs(1);
    f(1);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] - 1 << " ";
    cout << "\n";
    return 0;
}

