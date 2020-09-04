#include <bits/stdc++.h>

using namespace std;

int n;
int mid = 32;
int dp[2][3][65];
int v[100010];

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int last = 0;
    for (int i = 0; i < 65; ++i)
        dp[last][1][i] = dp[last][0][i] = -1e9;

    for (int i = n - 1; i >= 0; i--) {
        int cur = 1 - last;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 65; ++k) {
                int r = k - mid;
                int &ans = dp[cur][j][k] = -1e9;
                if(j == 0) {
                    ans = max(ans, dp[last][j][r + mid]);
                    ans = max(ans, dp[last][1][max(r, v[i]) + mid] + v[i]);
                } 
                if(j == 1) {
                    ans = max(ans, dp[last][j][max(r, v[i]) + mid] + v[i]);
                    ans = max(ans, dp[last][2][max(r, v[i]) + mid] + v[i] - max(v[i], r));

                } 
                if(j == 2) 
                    ans = max(ans , dp[last][j][r + mid]);
                
            }
        }
        last = cur;
    }

    cout << max(0, dp[last][0][mid]) << "\n";
    return 0;
}

