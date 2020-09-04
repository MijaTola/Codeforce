#include <bits/stdc++.h>

using namespace std;

int n;
char s[510];
int dp[510][510];
string t = "";
int f(int l, int r) {
    if(l > r) return 0;
    int &ans = dp[l][r];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = l + 1; i <= r; ++i) 
        if(t[i] == t[l]) 
            ans = min(ans, f(l + 1, i - 1) + f(i, r));
    ans = min(ans, f(l + 1, r) + 1);
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; ++i)
        if(t.back() !=  s[i]) t += s[i];
    printf("%d\n", f(0, t.size() - 1));
    return 0;
}
