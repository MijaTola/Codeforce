#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<long long> v[65], G[100010];
int dis[100010];
int vis[100010];
int ans;
void dfs(int u, int d, int p) {
    dis[u] = d;
    vis[u] = 1;
    for (auto v: G[u]) {
        if(v == p) continue;    
        if(vis[v]) ans = min(ans, abs(dis[v]- dis[u]));
        else dfs(v, d + 1, u);
    }
    dis[u] = 0;
    vis[u] = 0;
}
 
int main() {
 
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        for (int j = 0; j <= 64; ++j) 
            if(x & (1LL << j)) v[j].push_back(i);
    }
    
    for (int i = 0; i <= 64; ++i) 
        if((int)v[i].size() >= 3) return cout << "3\n",0;
    
    set<pair<int,int > > s;
    for (int i = 0; i <= 64; ++i) {
        for (int j = 0; j < (int)v[i].size() - 1; ++j) {
            if(s.count({min(v[i][j], v[i][j + 1]), max(v[i][j], v[i][j + 1])})) continue;
            s.insert({min(v[i][j], v[i][j + 1]), max(v[i][j], v[i][j + 1])});
            G[v[i][j]].push_back(v[i][j + 1]);
            G[v[i][j + 1]].push_back(v[i][j]);
        }
    }
    
  
    ans = 1e9; 
    for (int i = 1; i <= n; ++i) 
        if(!vis[i]) dfs(i, 1, i);
    
    if(ans >= 1e9) return cout << "-1\n",0;
    cout << ans  + 1<< "\n";
    return 0;
}
