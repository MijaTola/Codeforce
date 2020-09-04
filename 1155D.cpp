#include <bits/stdc++.h>

using namespace std;

int n;
long long v[300010],x;
long long dp[300010][3][3];

long long f(int pos, int flag, int able) {
    if(pos == n or able == 2) return 0;
    long long &ans = dp[pos][flag][able];
    if(ans != -1) return ans;
    ans = 0;
    if(able == 0) {
        ans = max(ans, f(pos + 1, flag, 0));
        ans = max(ans, f(pos + 1, 0, 1) + v[pos]);
        ans = max(ans, f(pos + 1, 1, 1) + v[pos] * x);
        ans = max(ans, f(pos + 1, 2, 1) + v[pos] * x);
        ans = max(ans, f(pos + 1, 2, 2) + v[pos] * x);
        ans = max(ans, f(pos + 1, 2, 2) + v[pos]);
    } 
    if(able == 1) {
        if(flag == 0) {
            ans = max(ans, f(pos + 1, 0, 1) + v[pos]);
            ans = max(ans, f(pos + 1, 1, 1) + v[pos] * x);
            ans = max(ans, f(pos + 1, 2, 1) + v[pos] * x);
            ans = max(ans, f(pos + 1, 2, 2) + v[pos] * x);
            ans = max(ans, f(pos + 1, 2, 2) + v[pos]);
        }
        if(flag == 1) {
            ans = max(ans, f(pos + 1, 1, 1) + v[pos] * x);
            ans = max(ans, f(pos + 1, 2, 1) + v[pos] * x);
            ans = max(ans, f(pos + 1, 2, 2) + v[pos] * x);
            ans = max(ans, f(pos + 1, 2, 2) + v[pos]);
        }

        if(flag == 2) {
            ans = max(ans, f(pos + 1, 2, 1) + v[pos]);
            ans = max(ans, f(pos + 1, 2, 2) + v[pos]);
        }
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %lld", &n, &x);
    for (int i = 0; i < n; ++i)
        scanf("%lld", v + i);
    printf("%lld\n", f(0,0,0));
    return 0;
}

