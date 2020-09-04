#include <bits/stdc++.h>

using namespace std;

int n,m;
string s[20];
int dp[20][2];

int main(){

    for (int i = 0; i < 20; ++i)
        dp[i][0] = dp[i][1] = 1e9;

    cin >> n >> m;
    string x(m + 2, '0');
    int id = 1;
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        if(s[i] == x) {
            if(flag) id = i + 1;
        } else flag = 0;
    }
    m += 2;
    int dk = 0;
    while(s[id][dk] == '0' and dk < m) dk++;
    dp[id][1] = m - dk - 1;
    
    dk = m - 1;
    
    while(s[id][dk] == '0' and dk >= 0) dk--;
    dp[id][0] = dk;
    dp[id][0] = max(dp[id][0], 0);
    dp[id][1] = max(dp[id][1], 0);
    for (int i = id + 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(j) {
                int k = 0;
                while(s[i][k] == '0' and k < m) k++;
                int cnt = m - k - 1;
                cnt = max(cnt, 0);
                dp[i][j] = min(dp[i][j], dp[i - 1][0] + m);
                dp[i][j] = min(dp[i][j], dp[i - 1][1] + 2 * cnt + 1);
            } else {
                int k = m - 1;
                while(s[i][k] == '0' and k >= 0) k--;
                k = max(0, k);
                dp[i][j] = min(dp[i][j], dp[i - 1][0] + 2 * k + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][1] + m);
            }
        }
    }

    cout << (dp[n][0] == 1e9 ? 0 : dp[n][0]) << "\n";
    
    return 0;
}

