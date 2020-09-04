#include <bits/stdc++.h>

using namespace std;

long long res;
long long m,a,b,lim;
bool vis[1000010];

void f(int u) {
    if(u < 0 or u > lim or vis[u]) return;
    vis[u] = 1;
    res++;
    f(u + a);
    f(u - b);
}

int main() {
    
    scanf("%lld %lld %lld", &m, &a, &b);

    res = 1;
    vis[0] = 1;
    
    long long rans = 0;
    long long cur = (a + b - __gcd(a,b));

    for (int i = 0; i <= min(1LL * m, cur); ++i) {
        if(i - a >= 0 and vis[i - a]) {
            lim = i;
            f(i);
        }
        rans += res;
    }
    
    if(m <= cur) {
        printf("%lld\n", rans);
        return 0;
    }

    auto get = [] (long long x) {
        long long s = x + 1;
        long long c = x / __gcd(a,b);
        s += c * (c - 1) / 2 * __gcd(a,b);
        s += c * (x % __gcd(a,b) + 1);
        long long ans =(x * (x + 1) / 2)/ gcd
        return s;
    };
    
    rans += get(m) - get(cur);


    printf("%lld\n", rans);

    return 0;
}

