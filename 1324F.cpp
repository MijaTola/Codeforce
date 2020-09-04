#include <bits/stdc++.h>

using namespace std;

int n,x,y;
int col[200010];
int dp[200010];
int dp2[200010];
vector<int> G[200010];

void dfs (int u, int p = -1) {
    dp[u] = col[u] ? 1 : -1;
    for (int v: G[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u] += max(0, dp[v]);     
    }
}

void f(int u, int p, int up) {
    dp2[u] = up + (col[u] ? 1 : -1);
    
    for (int v: G[u]) {
        if(v == p) continue;
        dp2[u] += max(0, dp[v]);
    }

    for (int v: G[u]) {
        if(v == p) continue;
        dp2[u] -= max(0, dp[v]);
        f(v, u, max(0, dp2[u]));
        dp2[u] += max(0, dp[v]);
    }
    
}

int main() {
    
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", col + i);

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dfs(1);
    f(1,1,0);

    for (int i = 1; i <= n; ++i)
        printf("%d ", dp2[i]);
    puts("");

    return 0;
}
