#include <bits/stdc++.h>

using namespace std;

int n,a,b;
int v[110];
int c[110];
int dp[110][110][110][2];


int main() {
    memset(dp, 30, sizeof dp);
    cin >> n;
    
    a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        c[x]++;
        if(!x) continue;
        if(x & 1) {
            v[i] = 1;
        } else {
            v[i] = 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if(!c[i]) {
            if(i & 1) a++;
            else b++;
        }
    }

    for (int i = 0; i < 110; ++i)
        for (int j = 0; j < 110; ++j)
            dp[n + 1][i][j][0] = dp[n + 1][i][j][1] = 0;

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= a; ++j) {
            for (int k = 0; k <= b; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if(!v[i]) {
                        if(j) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i + 1][j - 1][k][1] + (l == 0));
                        if(k) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i + 1][j][k - 1][0] + (l != 0));
                    } else {
                        if(l == v[i] % 2) dp[i][j][k][l] = min(dp[i][j][k][l], dp[i + 1][j][k][v[i] % 2]);
                        else dp[i][j][k][l] = min(dp[i][j][k][l], dp[i + 1][j][k][v[i] % 2] + 1);
                    }
                }
            }
        }
    }
  
    cout << min(dp[1][a][b][0], dp[1][a][b][1]) << "\n";
  
    return 0;
}

