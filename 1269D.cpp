#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[300010][2];
int v[300010];

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {
            if(j) {
                dp[i][j] = max(dp[i][j], dp[i + 1][0] + (v[i] - 1) / 2);
                if(v[i] >= 3 and v[i + 1] > 0) 
                    dp[i][j] = max(dp[i][j], dp[i + 1][1] + ((v[i] - 2) / 2) + 1);
            } else {
                if(v[i + 1] > 0 and v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][1] + (v[i] - 1) / 2 + 1);
                dp[i][j] = max(dp[i][j], dp[i + 1][0] + v[i] / 2);
                dp[i][j] = max(dp[i][j], dp[i + 2][0] + v[i + 1]);
            }
        }
    }

    cout <<  dp[1][0] << "\n";
    return 0;
}

