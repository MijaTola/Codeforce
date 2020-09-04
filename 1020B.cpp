#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[1010];
int vis[1010];
void dfs(int u) {
    vis[u]++;
    if(vis[u] == 2) return;
    for (int v: G[u]) dfs(v);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        G[i].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        memset(vis,0,sizeof vis);
        dfs(i);
        for (int j = 1; j <= n; ++j) {
            if(vis[j] == 2) cout << j << " ";
        }
        
    }
    return 0;
}

