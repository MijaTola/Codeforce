#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int k,a,b;
int dp[1111][1111];

int main(){
    
    scanf("%d %d %d", &k, &a, &b);

    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };

    int den = modpow(1LL * a * b, mod - 2);

    for (int i = k - 1; i >= 0; i--) {
        for (int j = 0; j <= k; ++j) {
            if(i + j >= k) {
                dp[i][j] = 
            } else {
                dp[i][j] = (((a * dp[i + 1][j]) % mod + (b * dp[i][j + i]) % mod) % mod) * den;
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[1][0] << "\n";

    return 0;
}

