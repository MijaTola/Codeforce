#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        int ans = 0;
        while(n != 0) {
            ans += (n % k);
            if(n >= k) ans++;
            n /= k;
        }
        cout << ans << "\n";

    }
    return 0;
}

