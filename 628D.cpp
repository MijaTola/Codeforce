#include <bits/stdc++.h>

using namespace std;

int m,d;
string a,b;
const int mod = 1e9 + 7;

int dp[2010][2][2020];

int main() {

    cin >> m >> d >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) {
        if(a[i] == '0') a[i] = '9';
        else { 
            a[i]--;
            break;
        }
    }
    
    auto f = [] (string &s) {

        memset(dp, 0, sizeof dp);
        dp[s.size()][0][0] = dp[s.size()][1][0] = 1;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < m; ++k) {
                    int lim = 9;
                    if(j) lim = s[i] - '0';
                    for (int l = 0; l <= lim; ++l) {
                        if(i & 1 and l != d) continue;
                        if(!(i & 1) and l == d) continue;
                        dp[i][j][k] += dp[i + 1][l == lim and j][((k * 10) + l) % m];
                        dp[i][j][k] %= mod;
                    }
                }
            }
        }
        return dp[0][1][0];
    };

    cout << (f(b) - f(a) + mod) % mod << "\n";
    return 0;
}

