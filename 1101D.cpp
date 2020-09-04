#include <bits/stdc++.h>

using namespace std;

int n;
int b[400010];
int dp[400010];
vector<int> pr[400010];
vector<int> G[400010];
set<pair<int,int> > s;

int dfs(int u, int p, int g) {
    s.insert({u, g});
    dp[u] = 1;
    int ans = 1;
    for (int v: G[u]) {
        if(v == p or b[v] % g != 0) continue;
        ans = max(ans, dfs(v, u, g));
        ans = max(ans, dp[v] + dp[u]);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    return ans;
}

int main() {

    scanf("%d", &n);

    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
        int x = b[i];
        flag &= x == 1;
        for (int j = 2; j * j <= x; ++j) {
            int cnt = 0;
            while(x % j == 0) x /= j, cnt++;
            if(cnt) pr[i].push_back(j);
        }
        if(x > 1) pr[i].push_back(x);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    if(flag) return puts("0"), 0;
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int x: pr[i]) {
            if(s.count({i, x})) continue;
            ans = max(ans, dfs(i, i, x));
        }
    }

    printf("%d\n", ans);
    return 0;
}

