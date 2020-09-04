#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010][11][2];

int main() {

    int n,m,dk;
    string s,t;

    cin >> n >> m >> dk >> s >> t;
    
    for (int i = 0; i < 1010; ++i) {
        for (int j = 0; j < 1010; ++j) {
            for (int k = 0; k < 11; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if(k != dk)
                        dp[i][j][k][l] = -1e9;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            for (int k = dk - 1; k >= 0; k--) {
                for (int l = 0; l < 2; ++l) {
                    int &ans = dp[i][j][k][l];
                    if(l) {
                        if(s[i] == t[j]) {
                            ans = max(ans, dp[i + 1][j + 1][k][1] + 1);
                            ans = max(ans, dp[i + 1][j + 1][k + 1][1] + 1);
                            ans = max(ans, dp[i + 1][j + 1][k + 1][0] + 1);
                        }
                        ans = max(ans, dp[i + 1][j][k + 1][0]);
                        ans = max(ans, dp[i][j + 1][k + 1][0]);
                        ans = max(ans, dp[i + 1][j + 1][k + 1][0]);
                    } else {
                        ans = max(ans, dp[i + 1][j][k][l]);
                        ans = max(ans, dp[i][j + 1][k][l]);
                        ans = max(ans, dp[i + 1][j + 1][k][l]);
                        if(s[i] == t[j]) {
                            ans = max(ans, dp[i + 1][j + 1][k][1] + 1);
                            ans = max(ans, dp[i + 1][j + 1][k + 1][0] + 1);
                        }
                    }
                }
            }
        }
    }

    cout << max(0,dp[0][0][0][0]) << "\n";

    return 0;
}

