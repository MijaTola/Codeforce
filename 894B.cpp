#include <bits/stdc++.h>

using namespace std;

long long n,m,k;


const int mod = 1e9 + 7;
int main(){

    auto modpow = [] (long long a, long long b) {
        long long x = 1, y = a;
        while(b) {
            if(b & 1) x = (x * y) % mod;
            y = (y * y) % mod;
            b >>= 1LL;
        }
        return x % mod;
    };


    scanf("%lld %lld %lld",&n,&m,&k);

    if((m & 1) != (n & 1) and k == -1) {
        puts("0");
    } else {
        long long a = min(n,m);
        long long b = max(n,m);

        long long cur = modpow(2, a - 1);
        long long ans = modpow(cur, b - 1);

        printf("%lld\n", ans);
    }

    return 0;
}

