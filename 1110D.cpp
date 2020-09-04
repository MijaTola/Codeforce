#include <bits/stdc++.h>

using namespace std;

int v[1000010];
int dp[2][6][6];

int main() {

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }

    int last = 0;
    for (int pos = m; pos >= 1; pos--) {
        int cur = 1 - last;
        for (int a = 5; a >= 0; a--) {
            for (int b = 5; b >= 0; b--) {
                int &ans = dp[cur][a][b];

                int x = v[pos] - a;
                int y = v[pos + 1] - b;
                int z = v[pos + 2];
                int mn = min({x,y,z,2});

                for (int i = 0; i <= mn; ++i) {
                    ans = max(ans, dp[last][b + i][i] + (x - i) / 3 + i);
                }
            }
        }
        last = cur;
    }

    cout << dp[last][0][0] << "\n";

    return 0;
}

