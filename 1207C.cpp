#include <bits/stdc++.h>

using namespace std;

int n,a,b;
string s;
long long dp[200010][2];
long long f(int pos, int cur) {
    if(pos == n) {
        if(cur == 0) return 0;
        else return 1e17;
    }
    long long &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 1e17;
    if(s[pos] == '1') {
        if(cur == 1) ans = min(ans, f(pos + 1, 1) + a + 2 * b);
    } else {
        if(cur == 0) {
            ans = min(ans, f(pos + 1, 0) + a + b);
            ans = min(ans, f(pos + 1, 1) + 2 * a + 2 * b);
        } else {
            ans = min(ans, f(pos + 1, 1) + a + 2 * b);
            ans = min(ans, f(pos + 1, 0) + 2 * a + b);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> s;
        for (int i = 0; i < n; ++i) 
            dp[i][0] = dp[i][1] = -1;
        cout << f(0,0) + b  << "\n";
    }
    return 0;
}

