#include <bits/stdc++.h>

using namespace std;


int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    
    auto f = [](long long a, long long b) {
        return (a * b) / __gcd(a,b);
    };

    long long mn = 1e9;
    long long ans = 0;
    for (int i = 0; i < 200000000; ++i) {
        if(f(a + i, b + i) < mn) {
            mn = f(a + i, b + i);
            ans = i;
        }
    }

    printf("%lld\n", ans);
    return 0;
}

