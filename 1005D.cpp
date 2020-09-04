#include <bits/stdc++.h>

using namespace std;

string s;
int dp[2][3][2];

int main(){

    cin >> s;
    
    int last = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int cur = 1 - last;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                int &ans = dp[cur][j][k] = -1e9;
                int val = s[i] - '0';
                if(k) {
                    if(s[i] != '0') {
                        ans = max(ans, dp[last][(j * 10 + val) % 3][0]);
                        if((j * 10 + val) % 3 == 0) 
                            ans = max(ans, dp[last][(j * 10 + val) % 3][1] + 1);
                        ans = max(ans, dp[last][0][1]);
                    } else {
                        ans = max(ans, dp[last][(j * 10 + val) % 3][1] + 1);
                    }
                } else {
                    ans = max(ans, dp[last][(j * 10 + val) % 3][0]);
                    ans = max(ans, dp[last][0][1]);
                    if((j * 10 + val) % 3 == 0) 
                        ans = max(ans, dp[last][(j * 10 + val) % 3][1] + 1);
                }
            }
        }
        last = cur;
    }

    cout << dp[last][0][0] << "\n";
    return 0;
}
