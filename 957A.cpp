#include <bits/stdc++.h>

using namespace std;

int n;
string s;
long long dp[1010][10];
const int mod = 1e9+7;
int main(){

    cin >> n >> s;

    vector<int> v;

    for (int i = 0; i < n; ++i) {
        if(s[i] == 'C')v.push_back(0);
        if(s[i] == 'M')v.push_back(1);
        if(s[i] == 'Y')v.push_back(2);
        if(s[i] == '?')v.push_back(3);
    }

    dp[n][0] = dp[n][1] = dp[n][2] = dp[n][3] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; ++j) {
            if(v[i] != 3) {
                if(j != v[i]) dp[i][j] += dp[i + 1][v[i]];
                continue;
            }

            for (int k = 0; k < 3; ++k) {
                if(j != k) {
                    dp[i][j] += dp[i + 1][k];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    if(dp[0][3] >= 2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

