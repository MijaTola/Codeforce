#include <bits/stdc++.h>

using namespace std;

int n,K;
int lim;
int v[200010];
int dp[200010][3][3];

int main() {

    cin >> n >> K;

    vector<int> c;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        c.push_back(v[i]);
    }

    auto check = [&] (int dk) {
     
        dp[n][1][0] = dp[n][1][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; ++j) 
                for (int l = 0; l < 2; ++l) {
                    dp[i][j][l] = -1e9;
                    if(l) dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j | (v[i] >= dk)][!l] + 1);
                    else if(v[i] <= dk) dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j][!l] + 1);
                    dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j][l]);
                }
        }
        
        return dp[0][0][0] >= K or dp[0][0][1] >= K;
    };

    int a = -1, b = 1e9;
    
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(check(mid)) b = mid;
        else a = mid;
    }

    cout << b << "\n";
    return 0;
}

