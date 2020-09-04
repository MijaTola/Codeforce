#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[300010];
int v[300010];

int main() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    for (int i = n; i >= 1; i--) {
        if(v[i] & 1 and v[i + 1] & 1) dp[i] = max(dp[i], dp[i + 2] + (v[i] + v[i + 1]) / 2);
        dp[i] = max(dp[i], dp[i + 2] + min(v[i], v[i + 1]));
        dp[i] = max(dp[i], dp[i + 1] + v[i] / 2);
    }

    cout << dp[1] << "\n";
    return 0;
}
