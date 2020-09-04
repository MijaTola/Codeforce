#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[110][110][110];
int v[110];
char s[110];

long long f(int l, int r, int pr) {
    if(l > r) return 0;
    long long &ans = dp[l][r][pr];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = l + 1; i <= r; ++i) {
        if(s[l] == s[i]) {
            ans = max(ans, f(l + 1, i - 1, 1) + f(i, r, pr + 1));
            ans = max(ans, f(l + 1, i - 1, 1) + f(i, r, 1) + v[pr - 1]);
        } 
    }
    ans = max(ans, f(l + 1, r, 1) + v[pr - 1]);
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %s", &n, s);  
    for (int i = 0; i < n; ++i) 
        scanf("%d", v + i);

    cout << f(0, n - 1, 1) << "\n";
    return 0;
}

