#include <bits/stdc++.h>

using namespace std;

    int t;
int main() {

    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        
        long long p = 1, ans = 0;
    
        while(p < 1e18) {
            ans += n / p;
            p <<= 1LL;
        }
        cout << ans << "\n";
    }
    return 0;
}

