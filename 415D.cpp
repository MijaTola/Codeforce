#include <bits/stdc++.h>

using namespace std;

int n,k;
const int mod = 1e9 + 7;

int dp[2010][2010];
int f(int pos, int last) {
    if(pos == k) return 1;
    int &ans = dp[pos][last];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 1; i * last <= n; i++) 
        ans = (ans + f(pos + 1, i * last)) % mod;
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin>> n >> k;
    cout << f(0,1) << "\n";
    return 0;
}

