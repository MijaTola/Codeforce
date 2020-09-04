#include <bits/stdc++.h>

using namespace std;

int a[200010];
int b[200010];
long long dp[200010][2];

int main() {
    
    for (int i = 1; i < 200010; ++i)
        dp[i][1] = dp[i][0] = 1e9;

    int n,c;
    cin >> n >> c;

    for (int i = 1; i <= n - 1; ++i) 
        cin >> a[i];
    

    for (int i = 1; i <= n - 1; ++i) 
        cin >> b[i];
    
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i - 1]);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + b[i - 1] + c);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + b[i - 1]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i - 1]);
    }

    for (int i = 1; i <= n; ++i)
        cout << min(dp[i][0], dp[i][1] + c) << " ";
    cout << "\n";
    return 0;
}

