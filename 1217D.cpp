#include <bits/stdc++.h>

using namespace std;

int n,m,cur, ans, comp;
int vis[5010];
vector<pair<int,int> > G[5010];
int a[5010];

void dfs(int u) {
    vis[u] = 1;
    for (auto p: G[u]) {
        int v = p.first;
        if(vis[v] == 1) {
            ans = 2;
            a[p.second] = 2;
        } else if(vis[v] == 2) {
            a[p.second] = 1;
        } else {
            a[p.second] = 1;
            dfs(v);
        }
    }
    vis[u] = 2;
}

int main() {

    cin >> n >> m;
    ans = 0;

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back({y, i});
    }
    
    ans = 1;
    for (int i = 1; i <= n; ++i) 
        if(vis[i] == 0) dfs(i);
    
    cout << ans << "\n";
    
    for (int i = 0; i < m; ++i)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}

