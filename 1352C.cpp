#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        long long a = -1, b = 1e14;
        
        auto check = [&] (long long x) {
            long long cnt = x / n;
            long long left = x - cnt;
            return left;
        };
        
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(check(mid) >= k)  b = mid;
            else a = mid;
        }
        cout << b << "\n";
    }
    return 0;
}

