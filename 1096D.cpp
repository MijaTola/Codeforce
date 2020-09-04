#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string h = "hard";
int v[100010];
long long dp[100010][5];

long long f(int pos, int cur) {
    if(pos == n) {
        if(cur < 4) return 0;
        return 1e15;
    }
    long long &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 1e15;
    if(s[pos] == h[cur]) {
        ans = min(ans, f(pos + 1, cur) + v[pos]);
        ans = min(ans, f(pos + 1, cur + 1));
    } else {
        ans = min(ans, f(pos + 1, cur) + v[pos]);
        ans = min(ans, f(pos + 1, cur));
    }
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << f(0,0) << "\n";
    return 0;
}

