#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,string> v[1010];
int dp[1010][16];

int f(int pos, int mask) {
    if(pos == n) {
        if(__builtin_popcount(mask) == 3) return 0;
        else return 1e9;
    }
    if(dp[pos][mask] != -1) return dp[pos][mask];
    int ans = 1e9;

    int curmask = 0;
    for (int i = 0; i < (int)v[pos].second.size(); ++i) {
        int p = v[pos].second[i] - 'A';
        curmask |= (1 << p);
    }

    ans = min(ans, f(pos + 1, mask | curmask) + v[pos].first);
    ans = min(ans, f(pos + 1, mask));
    return dp[pos][mask] = ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i].first >>  v[i].second;
    
    int ans = f(0,0);
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

