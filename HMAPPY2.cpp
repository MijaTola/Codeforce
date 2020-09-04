#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,a,b,k;
        cin >> n >> a >> b >> k;

        long long da = n / a;
        long long db = n / b;
        long long g = __gcd(a,b);
        long long both = n / (max(a,b) * g);
        da -= both;
        db -= both;
        long long total = da + db;
        if(total >= k)  puts("Win");
        else puts("Lose");
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            if(i % a == 0 and i % b != 0) {
                cout << i << " a\n";
                ans++;
            }
            if(i % a != 0 and i % b == 0) {
                cout << i << " b\n";
                ans++;
            }
            
        }
        cout << total << " " << ans << " equals\n";
    }
    return 0;
}

