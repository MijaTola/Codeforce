#include <bits/stdc++.h>

using namespace std;

int cnt,n;
int ini[200010];
int fin[200010];
long long a[200010];
vector<int> G[200010], path;
void dfs(int u, int p) {
    ini[u] = cnt;
    path.push_back(u);
    cnt++;
    for (int v: G[u]) {
        if(v != p) {
            dfs(v, u);
            a[u] += a[v];
        }
    }
    fin[u] = cnt - 1;
}

long long dp[200010][3];
long long f(int pos, int k) {
    if(pos == n) {
        if(k == 2) return 0;
        return -1e16;
    }
    long long &ans = dp[pos][k];
    if(ans != -1) return ans;
    ans = -1e16;
    ans = max(ans, f(pos + 1, k));
    if(k < 2) ans = max(ans, f(fin[path[pos]] + 1, k + 1) + a[path[pos]]);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cnt = 0;
    dfs(1,-1);
    
    long long ans = f(0,0);
    
    if(ans < -1e15) cout << "Impossible\n";
    else cout << ans << "\n";
    return 0;
} 
