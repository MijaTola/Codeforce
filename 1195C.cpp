#include <bits/stdc++.h>

using namespace std;

int n;
int v[3][100010];
long long dp[3][100010];
long long f(int pos, int flag) {
    if(pos == n) return 0;
    long long &ans = dp[flag][pos];
    if(ans != -1) return ans;
    ans = 0;
    if(flag == 1) ans = max(ans, f(pos + 1, 0) + v[1][pos]);
    if(flag == 0) ans = max(ans, f(pos + 1, 1) + v[0][pos]);
    ans = max(ans, f(pos + 1, flag));
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[0][i];
    for (int i = 0; i < n; ++i)
        cin >> v[1][i];
    
    cout << max(f(0,1), f(0,0)) << "\n";
    return 0;
}

