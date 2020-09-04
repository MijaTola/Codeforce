#include <bits/stdc++.h>

using namespace std;

string s;

int dp[20][3][3];
int f(int pos, int flag, bool zero) {
    if(pos == (int)s.size()) return 1;
    int &ans = dp[pos][flag][zero];
    if(ans != -1) return ans;
    ans = 0;
    int lim = 9;
    if(flag) lim = s[pos] - '0';
    for (int i = 0; i <= lim; i++) {
        if(i == 0 and zero) ans = max(ans, f(pos + 1, lim == i and flag, 1) );
        ans = max(ans, f(pos + 1, lim == i and flag, 0) * i);
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << f(0, 1, 1) << "\n";
    return 0;
}

