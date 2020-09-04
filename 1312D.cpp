#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353;

long long f[201000];
int n,m;
 
int main() {
 
    
    f[0] = 1;
 
    for (int i = 1; i < 201000; ++i) {
        f[i] = (i * f[i - 1]) % mod;
    }
 

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

    
    cin >> n >> m;
    
    if(n == 2) return puts("0"), 0;
    cout << ((n - 2) * (C(m, n - 1) * modpow(2, n - 3) % mod) % mod) % mod << "\n";

    return 0;
}
