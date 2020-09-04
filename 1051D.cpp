#include <bits/stdc++.h>

using namespace std;

int n,k;
const int mod = 998244353;
int dp[1010][4][4010];
int f(int pos, int mk, int cur) {
    if(pos == n) {
        if(mk == 3 or mk == 0) return cur + 1 == k;
        return cur + 2 == k;
    }
    int &ans = dp[pos][mk][cur];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i <= 3; ++i) {
        if(mk == 0) ans += f(pos + 1, i, cur + (i == 3));
        if(mk == 3) ans += f(pos + 1, i, cur + (i == 0));
        if(mk == 1) {
            if(mk == i) ans += f(pos + 1, i, cur);
            if(i == 3 or i == 0) ans += f(pos + 1, i, cur + 1);
            if(i == 2) ans += f(pos + 1, i, cur + 2);
        }
        if(mk == 2) {
            if(mk == i) ans += f(pos + 1, i, cur);
            if(i == 0 or i == 3) ans += f(pos + 1, i, cur + 1);
            if(i == 1) ans += f(pos + 1, i, cur + 2);
        }
        ans %= mod;
    }
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    int ans = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= 3; ++i) ans = (ans + f(1, i, 0)) % mod;
    printf("%d\n", ans);
    return 0;
}

