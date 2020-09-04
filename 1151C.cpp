#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
long long f(long long x) {
    long long p = 0, odd = 0, even = 0;
    while((1LL << (p + 1)) <= x) {
        if(p & 1LL) even = (even + (1LL << p)) % mod;
        else odd = (odd + (1LL << p)) % mod;
        p++;
    }
    long long left = ((x - (even + odd)) + mod) % mod;
    if(p & 1LL) even = (even + left) % mod;
    else odd = (odd + left) % mod ;
    return ((even * (even + 1)) % mod + (odd * odd) % mod) % mod;
}

int main() {
    long long l,r;
    cin >> l >> r;
    cout << ((f(r) - f(l - 1)) + mod) % mod << "\n";
    return 0;
}

