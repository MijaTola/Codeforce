#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
long long dp[200010][4][2];

int main() {

    int t;
    cin >> t;

    while(t--) {

        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        for (int i = 0; i < n + 5; ++i)
            for (int j = 0; j < 4; ++j)
                dp[i][j][0] = dp[i][j][1] = -1e9;
        
        dp[n][0][0] = dp[n][2][0] = dp[n][1][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 2; ++k) {
                    long long &ans = dp[i][j][k] = -1e9;
                    if(j == 0) {
                        if(i & 1) {
                            ans = max(ans, dp[i + 1][0][0]);
                            ans = max(ans, dp[i + 1][1][1] + v[i]);
                        } else {
                            ans = max(ans, dp[i + 1][0][0] + v[i]);
                            ans = max(ans, dp[i + 1][1][1]);
                        }
                    } 
                    if(j == 1) {
                        if(i & 1) {
                            ans = max(ans, dp[i + 1][1][(k + 1) % 2] + v[i]);
                            if(k % 2 == 0) ans = max(ans, dp[i + 1][2][0] );
                        } else {
                            ans = max(ans, dp[i + 1][1][(k + 1) % 2]);
                            if(k % 2 == 0) ans = max(ans, dp[i + 1][2][0] + v[i]);
                        }
                    }

                    if(j == 2) { 
                        if(i & 1) ans = max(ans, dp[i + 1][2][0]);
                        else ans = max(ans, dp[i + 1][2][0] + v[i]);
                    }
                }
            }
        }
        
        cout << dp[0][0][0] << "\n";
    }
    return 0;
}

