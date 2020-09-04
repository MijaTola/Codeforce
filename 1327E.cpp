#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 998244353 ;
long long n,m;
 
int main() {
 
    
    auto modpow = [] (long long a, long long b) {
        long long x = 1, y = a;
        while(b > 0) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1;
        }
        return x % mod;
    };
 
    

    cin >> n;
    for (int i = 1; i < n; ++i) {
        long long ans = (2 * 9 * 10 * modpow(10, n - i - 1)) % mod;
        if(i <= n - 2) ans += ((10 * 9 * 9 * ((n - i - 1)) % mod) * modpow(10, n - i - 2)) % mod;
        cout << ans % mod << " ";
    }
    
    cout << 10 << "\n";
    return 0;
}
