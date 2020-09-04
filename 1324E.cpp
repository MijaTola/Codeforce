#include <bits/stdc++.h>

using namespace std;

int n,h,l,r;
int v[2010];
int dp[2010][2010];
int main() {

    scanf("%d %d %d %d", &n, &h, &l, &r);

    for (int i = 0 ; i < n; ++i)
        scanf("%d", v + i);


    auto check = [] (int k) {
        return l <= k and k <= r;
    };

    for (int i =  n - 1; i >= 0; i--) {
        for (int j = 0; j < h; ++j) {
            dp[i][j] = max(dp[i][j], dp[i + 1][(j + v[i]) % h] + check((j + v[i]) % h) );
            dp[i][j] = max(dp[i][j], dp[i + 1][(j + v[i] - 1 + h) % h] + check((j + v[i] - 1 + h) % h));
        }
    }
    
    cout << dp[0][0] << "\n";
    return 0;
}

