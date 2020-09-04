#include <bits/stdc++.h>

using namespace std;

int dp[100010];
const int mod = 1e9 + 7;

int main() {
    int n;
    string s;

    cin >> s;
    n = s.size();
    dp[n] = 1;
    
    auto check = [s] (int i) {
        return (s[i] == 'n' or s[i] == 'u');
    };

    for (int i = n - 1; i >= 0; i--) {
        if(i + 1 < n) 
            if(check(i) and check(i + 1) and s[i] == s[i + 1]) {
                dp[i] += dp[i + 2];
                dp[i] %= mod;
            }

        if(s[i] != 'm' and s[i] != 'w') 
            dp[i] += dp[i + 1];
        dp[i] %= mod;
    }
    
    cout << dp[0] << "\n";

    return 0;
}

