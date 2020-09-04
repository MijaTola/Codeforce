#include <bits/stdc++.h>

using namespace std;

int n,k;
string s,t;
int dp[210][210][210];

int main() {


    cin >> n >> k >> s >> t;


    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                int &ans = dp[i][j][k];

                if(s[i] == t[0]) 
                    ans = max(ans, dp[i + 1][j + 1][k] + (t[0] == t[1] ? j : 0));

                if(s[i] == t[1])
                    ans = max(ans, dp[i + 1][j + (t[0] == t[1])][k] + j);

                if(k) {
                    ans = max(ans, dp[i + 1][j + 1][k - 1] + (t[0] == t[1] ? j : 0));
                    ans = max(ans, dp[i + 1][j + (t[0] == t[1])][k - 1] + j);
                }
            }
        }
    }

    cout << dp[0][0][k] << "\n";

    return 0;
}

