#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;
        vector<int> dp(n + 10);
        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        
        int ans = 0;
        
        for (int i = n; i >= 1; i--) {
            for (int j = i + i; j <= n; j += i) {
                if(v[i] < v[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        
        cout << ans + 1<< "\n";
    }
    return 0;
}

