#include <bits/stdc++.h>

using namespace std;

int vis[100010];
vector<int> G[100010];

int dfs(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    int ans = 1;
    
    for (int v: G[u]) 
        if(!vis[v]) ans += dfs(v);
    
    return ans;
}

int main() {
    
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    int total = 0;
    for (int i = 0; i < n; ++i) {
        if(!vis[i]) {
            total += dfs(i) - 1;
        }
    }
    cout << k - total << "\n";
    return 0;
}

