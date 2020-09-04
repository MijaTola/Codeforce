#include <bits/stdc++.h>

using namespace std;

int dp[1000010][3];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        
        vector<vector<int> > v(k);
        vector<int> cnt(k);

        for (int i = 0; i < n; ++i) {
            v[i % k].push_back(i);
            if(s[i] == '1') cnt[i % k]++;
        }
        

        auto f = [&] (const vector<int> &b) {
            
            for (int i = 0; i < (int)b.size(); ++i)
                dp[i][0] = dp[i][1] = dp[i][2] = 1e9;
            
            dp[b.size()][0] = dp[b.size()][1] = dp[b.size()][2] = 0;

            for (int i = b.size() - 1; i >= 0; i--) {
                for (int j = 0; j < 3; ++j) {
                    int &ans = dp[i][j];
                    if(j == 0) {
                        if(s[b[i]] == '1') {
                            ans = min(ans, dp[i + 1][0] + 1);
                            ans = min(ans, dp[i + 1][1]);
                        } else {
                            ans = min(ans, dp[i + 1][0]);
                            ans = min(ans, dp[i + 1][1] + 1);
                        }
                    }
                    if(j == 1) {
                        if(s[b[i]] == '1') {
                            ans = min(ans, dp[i + 1][1]);
                            ans = min(ans, dp[i + 1][2] + 1);
                        } else {
                            ans = min(ans, dp[i + 1][1] + 1);
                            ans = min(ans, dp[i + 1][2]);
                        }
                    }

                    if(j == 2) {
                        if(s[b[i]] == '1')  ans = min(ans, dp[i + 1][2] + 1);
                        else ans = min(ans, dp[i + 1][2]);
                    }
                }
            }
            return dp[0][0];
        };
    
        int total = 0;
        for (int i = 0; i < k; ++i) {
            total += cnt[i];
        }
        
        int ans = 1e9;
        for (int i = 0; i < k; ++i) {
            int c = f(v[i]);
            int d = total - cnt[i];
            ans = min(ans, c + d);
        }
        cout << ans << '\n';
    }

    return 0;
}

