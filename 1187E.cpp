#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[200010];
long long sum[200010];
long long dp[200010];
long long f(int u, int len, int p) {
    long long ans = 1;
    dp[1] += len;
    for (int v: G[u]) {
        if(v == p) continue;
        ans += f(v, len + 1, u);
    }
    return sum[u] = ans;
}

void dfs(int u, int p) {
    for (int v: G[u]) {
        if(v == p) continue;
        dp[v] = dp[u] + sum[1] - 2 * sum[v];
        dfs(v, u);
    }
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    f(1,1,0);
    dfs(1,0);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}

