#include <bits/stdc++.h>

using namespace std;

bool p[2000000];
vector<long long> pr,v;
const int mod = 1e9+7;

void build() {
    for (int i = 2; i < 2000000; ++i) {
        for (int j = i + i; j < 2000000; j += i)
            p[j] = 1;
    }

    for (int i = 2; i < 2000000; ++i)
        if(!p[i]) pr.push_back(i);

}

void f(long long n) {
    int id = 0, pf = pr[id];
    while(pf * pf <= n) {
        bool flag = 0;
        while(n % pf == 0) {
            flag = 1;
            n/= pf;
        }

        if(flag) v.push_back(pf);
        pf = pr[++id];
    }
    if(n != 1) v.push_back(n);

}

long long mul(long long a, long long b) {
    long long   result = 0;
    a %= mod;
    b %= mod;
    while(b) {
        if(b & 0x1) {
            result += a;
            result %= mod;
        }
        b >>= 1;
        if(a < mod - a) {
            a <<= 1;
        } else {
            a -= (mod - a);
        }
    }
    return result;
}

long long modpow(long long x, long long b) {
    if(b == 0) return 1;
    return (b & 1) ? mul(x, modpow(x, b - 1)) % mod : modpow(mul(x,x), b / 2) % mod;
}

int main() {
    build();
    long long x,n;
    cin >> x >> n;
    f(x);
    long long ans = 1;

    for (int cur: v) {
        long long val = n;
        long long cnt = 0;
        while(val) {
            cnt += val / cur;
            val /= cur;
        }
        ans = (ans * modpow(cur, cnt)) % mod;
    }
    cout << ans << "\n";
    return 0;
}

