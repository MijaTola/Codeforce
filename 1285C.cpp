#include <bits/stdc++.h>

using namespace std;

int main() {
    
    auto gLcm = [] (auto a, auto b) {
        return a * b / __gcd(a,b);
    };
    long long x;
    cin >> x;
    
    long long ans = LLONG_MAX;
    long long a = -1, b = -1;
    for (long long i = 1; i * i <= x; ++i) {
        if(x % i == 0) {
            long long lcm = gLcm(i, x / i);
            if(lcm == x) {
                if(max(i, x / i) < ans) {
                    ans = max(i, x / i);
                    a = i, b = x / i;
                }
            }
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}

