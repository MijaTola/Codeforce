#include <bits/stdc++.h>

using namespace std;

int n;
int v[110];

int dp[110][3];

int main() {
    memset(dp, 30, sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    dp[n][0] = dp[n][1] = dp[n][2] = 0;

    for (int dia = n - 1; dia >= 0; --dia) {
        for (int ultimo = 0; ultimo < 3; ++ultimo) {
            if(v[dia] == 0) 
                dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][0] + 1);
            if(v[dia] == 1) {
                if(ultimo != 1) dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][1]);
                else dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][0] + 1);
            }

            if(v[dia] == 2) {
                if(ultimo != 2) dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][2]);
                else dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][0] + 1);
            }

            if(v[dia] == 3) {
                if(ultimo != 2) dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][2]);
                if(ultimo != 1) dp[dia][ultimo] = min(dp[dia][ultimo], dp[dia + 1][1]);
            }
        }
    }
    
    cout << dp[0][0] << "\n";

    return 0;
}

