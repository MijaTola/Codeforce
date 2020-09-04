#include <bits/stdc++.h>

using namespace std;

long long dp[210][210][210];

long long dr[210];
long long dg[210];
long long db[210];

int main() {
    
    int r,g,b;
    cin >> r >> g >> b;
    

    for (int i = 1; i <= r; ++i) {
        cin >> dr[i];
    }

    for (int i = 1; i <= g; ++i) {
        cin >> dg[i];
    }

    for (int i = 1; i <= b; ++i) {
        cin >> db[i];
    }


    sort(dr + 1, dr + r + 1);
    sort(dg + 1, dg + g + 1);
    sort(db + 1, db + b + 1);

    for (int i = 0; i <= r; ++i) {
        for (int j = 0; j <= g; ++j) {
            for (int k = 0; k <= b; ++k) {
                long long &ans = dp[i][j][k] = 0;
                if(i and j) 
                    ans = max(ans, dp[i - 1][j - 1][k] + dr[i] * dg[j]);

                if(i and k) 
                    ans = max(ans, dp[i - 1][j][k - 1] + dr[i] * db[k]);

                if(j and k)
                    ans = max(ans, dp[i][j - 1][k - 1] + dg[j] * db[k]);
                
                if(i) ans = max(ans, dp[i - 1][j][k]);
                if(j) ans = max(ans, dp[i][j - 1][k]);
                if(k) ans = max(ans, dp[i][j][k - 1]);

            }
        }
    }
    
    cout << dp[r][g][b] << "\n";
    return 0;
}
