#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n,k;
vector<pair<int,int> > G[100010];
bool vis[100010];

int dfs(int u) {
    vis[u] = 1;
    int ans = 1;
    for (pair<int,int> v: G[u]) 
        if(!vis[v.first] and v.second == 0) 
            ans += dfs(v.first);
    return ans;
}

int modpow(int b, int e) {
    if(e == 0) return 1;
    long long p = modpow(b, e / 2);
    p = (p * p) % mod;
    return (e % 2 == 0) ? p : (b * p) % mod;
}

int main() {

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x,y,c;
        cin >> x >> y >> c;
        G[x].push_back({y,c});
        G[y].push_back({x,c});
    }
    
    int ans = modpow(n,k);
    for (int i = 1; i <= n; ++i) 
        if(!vis[i]) {
            ans -= modpow(dfs(i),k);
            ans += mod;
            ans %= mod;
        }
    cout << ans << "\n";
    return 0;
}

