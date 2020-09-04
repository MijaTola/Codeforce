#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[17][10010];
int vmn[17][17];
int lmn[17][17];
int dp[1 << 17][17][17];

int f(int mask, int cur, int ini) {
    if(__builtin_popcount(mask) == n) return lmn[ini][cur];
    int &ans = dp[mask][cur][ini];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < n; ++i) {
        if(mask & (1 << i)) continue;
        ans = max(ans, min(f(mask | (1 << i), i, ini), vmn[cur][i]));
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            scanf("%d", &v[i][j]);
    
    if(n == 1 and m == 1) return puts("0"),0;
    if(n == 1) {
        int ans = 1e9;
        for (int i = 0; i < m - 1; ++i)
            ans = min(ans, abs(v[0][i] - v[0][i + 1]));
        printf("%d\n", ans);
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            int mn = 1e9;
            for (int k = 0; k < m; ++k) 
                mn = min(mn, abs(v[i][k] - v[j][k]));
            vmn[i][j] = mn;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            int mn = 1e9;
            for (int k = 1; k < m; ++k) 
                mn = min(mn, abs(v[i][k] - v[j][k - 1]));
            lmn[i][j] = mn;
        }
    }
    
    int ans = 0;

    for (int i = 0; i < n; ++i) 
        ans = max(ans, f(1 << i,i,i));

    printf("%d\n", ans);
    
    return 0;
}

