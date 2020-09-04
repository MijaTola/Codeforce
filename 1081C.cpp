#include <bits/stdc++.h>

using namespace std;

int n,m,k;
const int mod = 998244353;
long long add(int x, int y) {
    return (x + y) % mod;
}

long long dp[2010][2010];

long long f(int pos, int dk) {
    if(pos == n - 1) return dk == k;
    long long &ans = dp[pos][dk];
    if(ans != -1) return ans;
    ans = 0;
    ans = add(ans,f(pos + 1, dk));
    ans = add(ans, (f(pos + 1, dk + 1) * (m - 1)) % mod);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    cout << (f(0, 0) * m) % mod << "\n";
    return 0;
}

