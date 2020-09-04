#include <bits/stdc++.h>

using namespace std;

int t,n,p,k;
int v[200010];
int dp[200010];
int c[200010];

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> p >> k;
        for (int i = 0; i < n; ++i)
            v[i] = dp[i] = c[i] = 0;
        for (int i = 0 ; i < n; ++i) 
            cin >> v[i];
        sort(v, v + n);
        
    
        for (int i = k - 1; i < n; ++i) {
            dp[i] = v[i];
            if(c[i - k]) dp[i] += dp[i - k];
            c[i] += c[i - k] + 1;
        }

        for (int i = 1; i < n; ++i)
            v[i] += v[i - 1];


        int ans = 0;
    
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            if(dp[i] <= p) {
                cur = c[i] * k;
            }

            int left = max(p - dp[i], 0);
            int r = i - cur + 1;
            int pos = upper_bound(v, v + r, left) - v - 1;
            if(pos < 0 or pos >= n or v[pos] > p) pos = -1;
            ans = max(ans, cur + (pos + 1));
        }

        cout << ans << "\n";
           
    }
    return 0;
}

