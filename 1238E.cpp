#include <bits/stdc++.h>

using namespace std;

int n,m;
string s;
int cnt[21][21];
int dp[1 << 21];
int f(int mask, int pos) {
    if(mask == (1 << m) - 1) return 0;
    int &ans = dp[mask];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = 0; i < m; ++i) {
        if(!(mask & (1 << i))) {
            int cur = 0;
            for (int j = 0; j < m; ++j) 
                if(i != j) 
                    cur += cnt[min(i,j)][max(i,j)] * (mask & (1 << j) ? 1 : -1) ;

            ans = min(ans, f(mask | (1 << i), pos + 1) + cur * pos);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; ++i) 
        cnt[min(s[i] - 'a', s[i + 1] - 'a')][max(s[i] - 'a', s[i + 1] - 'a')]++;
    cout << f(0, 0) << "\n";
    return 0;
}

