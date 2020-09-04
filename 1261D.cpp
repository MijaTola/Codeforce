#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long dp[2010][4010];

int mid = 2001;
void task1() {
    int n,k;
    cin >> n >> k;

    vector<int> v(n);

    for (int &x: v)
        cin >> x;


    for (int i = 2001; i < 4010; ++i)
        dp[n][i] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4000; ++j) {
            dp[i][j] = 0;
            int dk = j - mid;
            if(v[i] == (v[i + 1] % n)) {
                dp[i][j] += dp[i + 1][dk + mid];
                dp[i][j] += dp[i + 1][dk + mid] * (k - 2);
            } else {
                dp[i][j] += dp[i + 1][dk + 1 + mid];
                dp[i][j] += dp[i + 1][dk - 1 + mid];
            }
        }
    }
    
    cout << dp[0][0] << "\n";
}
int main() {

    task1();

    return 0;
}

