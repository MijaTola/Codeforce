#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[110];
int dp[110][10010];
int f(int pos, int w) {
    if(pos == n) {
        if(w <= 0) return 0;
        return 1e9;
    }
    if(w <= 0) return 0;
    int cur = 0;
    int del = 0;
    int &ans = dp[pos][w];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = pos; i < n; ++i) {
        int s = v[i] - cur++;
        del += max(0,s);
        ans = min(ans, f(i + 1, w - del) + 1);
    }
    ans = min(ans, f(pos + 1, w));
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    reverse(v, v + n);
    int ans = f(0, m);
    if(ans == 1e9) puts("-1");
    else cout << ans << "\n";
    return 0;
}

