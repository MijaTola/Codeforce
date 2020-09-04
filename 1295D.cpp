#include <bits/stdc++.h>

using namespace std;

int main() {
    
    auto phi = [] (long long n) -> long long {
        long long ans = n;
        for (long long p = 2; p * p <= n; p++) {
            if(n % p == 0) {
                while(n % p == 0) n /= p;
                ans -= ans / p;
            }
        }
        if(n > 1) ans -= ans / n;
        return ans;
    };

    int t;
    cin >> t;

    while(t--) {
        long long a,m;
        cin >> a >> m;
        long long g = __gcd(a,m);
        m /= g;
        cout << phi(m) << "\n";
    }
    return 0;
}

