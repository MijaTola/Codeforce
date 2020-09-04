#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[100010];
bool vis[100010];
int sz[100010];

int dfs(int u) {
    int ans = 0;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        ans += dfs(v);
        sz[u] += sz[v];
    }
    if(sz[u] % 2 == 0 and u != 1) ans++;
    return ans;
}

int main(){
    for (int i = 0; i < 100010; ++i) {
        vis[i] = 0;
        sz[i] = 1;
    }

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    if(n & 1) return cout << "-1\n",0;
    vis[1] = 1;
    cout << dfs(1) << "\n";

    return 0;
}

