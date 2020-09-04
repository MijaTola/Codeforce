#include <bits/stdc++.h>

using namespace std;

int df[5000100];

int f(int n) {
    if(n == 1) return 0;
    int ans = min(n * (n - 1) / 2, n);
    for (int i = 2; i < n; ++i) {
        if(n % i == 0) {
            int cur = n / i;
            int total = (cur) * (cur - 1) / 2;
            total *= i;
            ans = min(ans, f(n / i) + total);
        }
    }
    return ans;
}

const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 4, p = 3; i < 5000100; i += 2, p++)
        df[i] = p;
    df[2] = 1;
    for (int i = 2; i < 5000100; i++) 
        if(i & 1) df[i] = i;
    
    int t,l,r;
    cin >> t >> l >> r;
    long long dt = 1;
    long long ans = 0;
    for (int i = l; i <= r; ++i) {
        dt = (dt * t) % mod;
        ans = (ans + ((long long)dt * df[i]) % mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}

