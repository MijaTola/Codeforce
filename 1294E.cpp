#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,m;
    cin >> n >> m;
    int dp[m + 10];
    int v[n + 10][m + 10];
    
    for (int i = 0; i < m; ++i)
        dp[i] = 1e9;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];
    
    dp[m] = 0;

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; ++j) {
            int cost = j;;
            for (int k = 0, ini = j, col = i + 1; k < n; ++k, ini++, col += m) 
                cost += v[ini % n][i] != col;
            
            dp[i] = min(dp[i], dp[i + 1] + cost);
        }
    }
    cout << dp[0] << "\n";
    return 0;
}

