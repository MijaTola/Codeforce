#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int dp[100010][3][3];
int f(int pos, bool last, int flag) {
    if(pos == n) return 0;
    int &ans = dp[pos][last][flag];
    if(ans != -1) return ans;
    ans = 0;
    int cur = s[pos] - '0';
    if(flag == 0) {
        ans = max(ans, f(pos + 1, last, flag));
        if(last == cur) ans = max(ans, f(pos + 1, !last, flag) + 1);
        else {
            ans = max(ans, f(pos + 1, !last, 1) + 1);
            ans = max(ans, f(pos + 1, !last, 2) + 1);
        }
    }
    if(flag == 1) {
        ans = max(ans, f(pos + 1, last, flag));
        ans = max(ans, f(pos + 1, last, 2));
        if(last != cur) {
            ans = max(ans, f(pos + 1, !last, flag) + 1);
            ans = max(ans, f(pos + 1, !last, 2) + 1);
        }
    }
    if(flag == 2) {
        ans = max(ans, f(pos + 1, last, flag));
        if(last == cur) ans = max(ans, f(pos + 1, !last, flag) + 1);
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    cout << max(f(0,0,0), f(0,1,0)) << "\n";
    return 0;
}

