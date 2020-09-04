#include <bits/stdc++.h>

using namespace std;

int v[510];
int dp[510][510];
int dp2[510][510];

int f(int l, int r) {
    if(l == r) return v[r];
    int &ans = dp[l][r];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = l; i < r; ++i) {
        if(f(l,i) < 1e9 and  f(l, i) == f(i + 1, r)) {
            ans = f(l,i) + 1;
        }
    }
    return ans;
}

int fu(int l, int r) {
    if(f(l,r) != 1e9) return r - l;
    int &ans = dp2[l][r];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = l; i < r; ++i)
        ans = max(ans, fu(l, i) + fu(i + 1, r));
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << n - fu(0, n - 1) << "\n";
    return 0;
}

