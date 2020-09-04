#include <bits/stdc++.h>

using namespace std;

int n;
int dp[2000010];
int f[2000010];
int w[2000010];

int main() {
    memset(f, -1, sizeof f);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        f[x] = y; w[x] = z;
    }
    
    for (int i = 2000000; i >= 0; i--) {
        if(f[i] != -1)
            dp[i] = max(dp[i], dp[i + w[i]] + f[i]);
        dp[i] = max(dp[i], dp[i + 1]);
    }
    cout << dp[0] << "\n";
    return 0;
}

