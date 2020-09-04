#include <bits/stdc++.h>

using namespace std;

long long a,b,n;
long long fact[1000100];
const int mod = 1e9 + 7;
bool ver(int u) {
    while(u > 0) {
        if(u % 10 != a and u % 10 != b) return 0;
        u /= 10;
    }
    return 1;
}

long long modpow(int x, int y) {
    if(!y) return 1;
    if(y & 1) return modpow(x, y - 1) * x % mod; 
    long long ans = modpow(x,y >> 1);
    return (ans * ans) % mod;
}
long long C(int n, int k) {
    long long l = fact[n];
    long long m = (fact[k] * fact[n - k]) % mod;
 //   cout << l << " " << n << " " << m << " " << k << "\n";
    return (l * modpow(m, mod - 2)) % mod;
}
int main(){

    fact[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        fact[i] = (i * fact[i - 1]) % mod;

    cin >> a >> b >> n;
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        if(ver((i * a) + ((n - i) * b))) {
            ans = (ans + C(n,i)) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}

