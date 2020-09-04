#include <bits/stdc++.h>

using namespace std;

int n,k,x,y;
vector<int> G[210];
int a[210];
int dp[210][210];

int f(int u, int cur, int p) {
    if(dp[u][cur] != -1) return dp[u][cur];
    int a1 = a[u], a2 = 0;
    if(!cur) {
        for (int v: G[u]) {
            if(v == p) continue;
            a1 += f(v, k, u);
            a2 += f(v, 0, u);
        }
        return dp[u][cur] = max(a1, a2);
    } else {
        for (int v: G[u]) {
            if(v == p) continue;
            a2 += f(v, cur - 1, u);
        }
        return a2;
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &k); 

    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    printf("%d\n", f(1, 0, 1));
    return 0;
}

