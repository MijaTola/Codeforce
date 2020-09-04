#include <bits/stdc++.h>

using namespace std;

int n,m, color;
vector<int> G[200010];
bool vis[200010];
int cmp[200010];
int bel[200010];

void dfs(int u) {
    if(vis[u]) return;
    bel[u] = color;
    cmp[color]++;
    vis[u] = 1;
    for (int v: G[u]) 
        dfs(v);
}

int f(int u, int cur, int parent) {
    if(vis[u]) {
        if(cmp[bel[u]] == cur) return 1;
        else return -1e9;
    }
    
    vis[u] = 1;
    int ans = 1;
    for (int v: G[u]) {
        if(v == parent) continue;
        ans += f(v, cur + 1, u);
    }
    return ans;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    color = 0;
    for (int i = 1; i <= n; ++i)
        if(!vis[i]) dfs(i), color++;

    memset(vis, 0, sizeof vis);
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        if(!vis[i] and cmp[bel[i]] > 2) {
            vis[i] = 1; 
            int a = f(G[i][0], 1 , i);
            ans += (a == cmp[bel[i]]);
        }
    cout << ans << "\n";
    return 0;
}
