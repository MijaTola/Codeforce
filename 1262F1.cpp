#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long dp[2010][5030];
int v[2010];
int n,k;

int mid = 2010;

void task1() {
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = mid + 1; i < 5030; ++i)
        dp[n][i] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4010; ++j) {
            dp[i][j] = 0;
            int dk = j - mid;
            if(v[i] == (v[(i + 1) % n])) {
                dp[i][j] += dp[i + 1][dk + mid];
                dp[i][j] %= mod;
                dp[i][j] += dp[i + 1][dk + mid] * (k - 1);
                dp[i][j] %= mod;
            } else {
                dp[i][j] += dp[i + 1][dk + 1 + mid];
                dp[i][j] %= mod;
                dp[i][j] += dp[i + 1][dk - 1 + mid];
                dp[i][j] %= mod;
                dp[i][j] += dp[i + 1][dk + mid] * (k - 2);
                dp[i][j] %= mod;
            }
        }
    }
    
    cout << dp[0][mid] << "\n";
}
int main() {

    task1();

    return 0;
}

