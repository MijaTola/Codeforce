#include <bits/stdc++.h>

using namespace std;

int n;
int v[2010];
int dp[2010][4];

int main() {
    
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; ++j) {
            if(j == 0) {
                dp[i][j] = max(dp[i][j], dp[i + 1][0] + (v[i] == 1));
                dp[i][j] = max(dp[i][j], dp[i + 1][1] + (v[i] == 2));
            }
            if(j == 1) {
                dp[i][j] = max(dp[i][j], dp[i + 1][1] + (v[i] == 2));
                dp[i][j] = max(dp[i][j], dp[i + 1][2] + (v[i] == 1));
            }
            if(j == 2) {
                dp[i][j] = max(dp[i][j], dp[i + 1][2] + (v[i] == 1));
                dp[i][j] = max(dp[i][j], dp[i + 1][3] + (v[i] == 2));
            }
            if(j == 3) {
                dp[i][j] = max(dp[i][j], dp[i + 1][3] + (v[i] == 2));
            }
        }
    }

    printf("%d\n", dp[0][0]);


    return 0;
}
