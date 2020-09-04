#include <bits/stdc++.h>

using namespace std;

int t;

int main() {

    cin >> t;

    while(t--) {
        long long n,x;
        cin >> n >> x;
        
        auto sum = [&] (long long s) {
            long long ans = 0;
            while(s > 0) {
                ans += s % 10;
                s = s / 10;
            }
            return ans;
        };
        
        long long cur = 1;

        long long ans = 0;
        while(sum(n) > x) {
            ans += abs(10 - n % 10) * cur;
            n /= 10;
            n++;
            cur *= 10;
        }

        cout << ans << "\n";

    }

    return 0;
}

