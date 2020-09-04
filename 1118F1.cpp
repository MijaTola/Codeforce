#include <bits/stdc++.h>

using namespace std;

int v[300010];
bool vis[300010];
vector<int> G[300010];
int c[300010][3];

void dfs(int u) {
    vis[u] = 1;
    c[u][v[u]]++;
    for (int vv: G[u]) {
        if(!vis[vv]) {
            dfs(vv);
            c[u][0] += c[vv][0];
            c[u][1] += c[vv][1];
            c[u][2] += c[vv][2];
        }
    }
}

int f(int u) {
    vis[u] = 1;
    int totalr = c[1][1];
    int totalb =  c[1][2];
    int rcur = c[u][1];
    int bcur = c[u][2];
    int topr = totalr - rcur;
    int topb = totalb - bcur;
    int ans = 0;
    if(topr and rcur and !topb and !bcur) ans++;
    if(topb and bcur and !topr and !rcur) ans++;
    if(topr and bcur and !topb and !rcur) ans++;
    if(topb and rcur and !topr and !bcur) ans++;
    for (int vv: G[u]) {
        if(vis[vv]) continue;
        ans += f(vv);
    }
    return ans;
}
int main() {
    int n;cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(vis, 0, sizeof vis);
    dfs(1);
    memset(vis, 0, sizeof vis);
    cout << f(1) << "\n";
    return 0;
}

