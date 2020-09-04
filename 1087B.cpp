#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    long long mn = LLONG_MAX;
    for (int i = 1; i <= 1000; ++i) {
        long long mod = i;
        long long x = n / mod;
        long long ans = x * k + mod;
        if((ans / k) * (ans % k) == n and ans != 0) {
            mn = min(mn, ans);
        }
    }
    cout << mn << "\n";
    return 0;
}

