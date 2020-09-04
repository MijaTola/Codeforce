#include <bits/stdc++.h>

using namespace std;

int n;
int v[1010];
long long C[1010][1010];
long long dp[1010];

const int mod = 998244353;


int main() {
    
    auto f = [] (auto n, auto k) {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= min(i, k); ++j) {
                if(j == 0 or j == i) C[i][j] = 1;
                else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
    };

    f(1000, 1000);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    dp[n] = 1;
    
    long long ans = 0;
    for (int pos = n - 1; pos >= 0; pos--) {
        if(v[pos] <= 0 or pos + v[pos] >= n) continue;
        dp[pos] = C[n - pos - 1][v[pos]];
        for (int i = pos, k = 1; i < n; ++i, k++) {
            if(k - 1 >= v[pos] and v[pos] > 0) {
                dp[pos] += (C[i - pos - 1][v[pos]] * dp[i]) % mod;
                dp[pos] %= mod;
            }
        }
        ans += dp[pos];
        ans %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}

