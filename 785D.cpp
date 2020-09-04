#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
long long f[201000];
int a[200010];
int b[200010];
 
int main() {
 
    
    f[0] = 1;
 
    for (int i = 1; i < 201000; ++i)
        f[i] = (i * f[i - 1]) % mod;
 
    auto modpow = [] (int a, int b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };
 
    auto C = [modpow] (int n, int k) {
        long long num = f[n];
        long long den = (f[(n - k + mod) % mod] * f[k]) % mod;
        return num * modpow(den, mod - 2) % mod;
    };

    string s;
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '(') a[i] = 1;
        else b[i] = 1;
    }

    for (int i = 1; i < (int)s.size(); ++i)
        a[i] += a[i - 1];

    for (int i = s.size() - 1; i >= 0; --i)
        b[i] += b[i + 1];

    long long ans = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        long long x = a[i];
        long long y = b[i + 1];
        if(s[i] != '(' or b[i] == 0) continue;
        ans = (ans + C(x + y - 1, x)) % mod;
    }
    cout << ans << "\n";
    return 0;
}

