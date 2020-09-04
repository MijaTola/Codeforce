#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
vector<int> G[100010];
int vis[100010];
bool f(int u, int parent) {
    if(vis[u] == 2) return 0;
    if(vis[u] == 1) return 1;
    vis[u] = 1;
    bool ans = 0;
    for (int v: G[u]) 
        if(v != parent)ans |= f(v,u);
    vis[u] = 2;
    return ans;
}
int main () {
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        if(!vis[i]) ans += !f(i,0);
    cout << ans << "\n";
    
    return 0;
}
