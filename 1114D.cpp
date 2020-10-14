#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int dp[5010][5010][2];

int f(int l, int r,  int flag) {
    if(l == 0 and r == n - 1) return 0;

    int &ans = dp[l][r][flag];

    if(ans != -1) return ans;
    ans = 1e9;
    int val = flag  ? v[r] : v[l];

    if(l) ans = min(ans, f(l - 1, r, 0) + (val != v[l - 1]));
    if(r + 1 < n) ans = min(ans, f(l, r + 1, 1) + (val != v[r + 1]));

    return ans;
}
int main() {

    memset(dp, -1, sizeof dp);
    cin >> n;
    v.resize(n);
    for (int &x: v)
        cin >> x;

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, f(i,i,0));
    }

    cout << ans << "\n";
    
    return 0;
}

