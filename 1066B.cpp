#include <bits/stdc++.h>

using namespace std;

int n,r,x;
vector<int> v;
int dp[1010][4000];
int f(int pos, int last) {
    if(pos == (int)v.size()) {
        if(last > n) return 0;
        return 1e9;
    }
    int &ans = dp[pos][last];
    if(ans != -1) return ans;
    ans = 1e9;
    int dl = v[pos] - r + 1;
    if(last >= dl) {
        ans = min(ans, f(pos + 1, v[pos] + r) + 1);
        ans = min(ans, f(pos + 1, last));
    }
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        if(x) v.push_back(i);
    }

    int ans = f(0,1);
    if(ans != 1e9) printf("%d\n", ans);
    else puts("-1");
    return 0;
}
