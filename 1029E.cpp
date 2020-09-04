#include <bits/stdc++.h>

using namespace std;

int n,x,y;
vector<int> G[200010];
long long dp[200010][7];

long long f(int u, int d, int p) {
    if(d + 1 > 4) return 1e10;
    if((int)G[u].size() == 1 and u != 1) {
        if(d <= 2) return 0;
        return 1e9;
    }
    long long &ans = dp[u][d];
    if(ans != -1) return ans;
    long long  cur = 0;
    for (int v: G[u]) {
        if(v == p) continue;
        cur += f(v, d + 1, u);   
    }
    ans = f(u, 1, p) + 1;
    return min(ans, cur);
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    printf("%lld\n", f(1,0,1));
    return 0;
}
