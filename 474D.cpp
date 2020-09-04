#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int t,k;
int dp[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> t >> k;

    dp[0] = 1;
    for (int i = 1; i < 100010; ++i) {
        dp[i] += dp[i - 1];
        dp[i] %= mod;
        if(i - k >= 0) dp[i] += dp[i - k];
        dp[i] %= mod;
    }
    
    for (int i = 1; i < 100010; ++i)
        dp[i] = (dp[i] + dp[i - 1]) % mod;

    while(t--) {
        int x,y;
        cin >> x >> y;
        cout << (dp[y] - dp[x - 1] + mod) % mod<< "\n";
    }
    return 0;
}

