#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    auto get = [&] (long long x) {
        return x * (x + 1) + x * (x - 1) / 2;
    };

    while(t--) {
        int n;
        cin >> n;
    
        int ans = 0;
        while(n > 1) {
            int a = -1, b = n;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                long long total = get(mid);
                if(n - total >= 0) a = mid;
                else b = mid;
            }
            n -= get(a);
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}

