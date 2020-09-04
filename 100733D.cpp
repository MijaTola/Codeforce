#include <bits/stdc++.h>

using namespace std;

int n;
int v[1000010];
long long dp[1000010];
long long f(int pos) {
    if(pos >= n) return 0;
    long long &ans = dp[pos];
    if(ans != -1) return ans;
    ans = 0;
    ans = max(ans, f(pos + 1));
    ans = max(ans, f(pos + 3) + v[pos]);
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << f(0) << "\n";
    return 0;
}

