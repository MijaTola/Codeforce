#include <bits/stdc++.h>

using namespace std;

int n;
string r[100010];
string dr[100010];
long long dp[100010][2];
int c[100010];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        dr[i] = r[i];
        dp[i][0] = dp[i][1] = 1e17;
        reverse(dr[i].begin(), dr[i].end());
    }
    
    dp[0][1] = 0;
    dp[0][0] = c[0];

    for (int i = 1; i < n; ++i) {
        if(r[i] >= r[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        if(r[i] >= dr[i - 1])
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        if(dr[i] >= r[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + c[i]);
        if(dr[i] >= dr[i - 1])
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + c[i]);
    }
    long long ans = min(dp[n - 1][0], dp[n - 1][1]);
    if(ans >= 1e17) return cout << "-1\n",0;
    cout << ans << "\n";
    return 0;
}

