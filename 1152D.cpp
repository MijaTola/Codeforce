#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int dp[1010][1010][3];
int n;
int f(int open, int close, int flag) {
    if(close > open or open > n or open + close == 2 * n) return 0;
    int &ans = dp[open][close][flag];
    if(ans != -1) return ans;
    ans = 0;
    if(flag) 
        ans = max(ans, f(open + 1, close, 0) + f(open, close + 1, 0));
    else {
        if(open < n) {
            if(close < open) {
                ans = max(ans, f(open + 1, close, 1) + f(open, close + 1, 0) + 1);
                ans = max(ans, f(open + 1, close, 0) + f(open, close + 1, 1) + 1);
            } else ans = max(ans, max(f(open + 1, close, 0),f(open + 1, close, 1) + 1));
        } else 
            if(close < n) 
                ans = max(ans, max(f(open, close + 1, 0),f(open, close + 1, 1) + 1));
    }
    ans %= mod;
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    cout << f(0,0,0) << "\n";
    return 0;
}
