#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
    
        int n;
        cin >> n;
        vector<int> a(33, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
         
            int p = 32;
            while(!(x & (1  << p))) p--;

            a[p]++;
        }

        long long ans = 0;

        auto get = [&] (long long x) {
            return (x * (x - 1)) / 2;
        };
        for (int i = 0 ; i < 33; ++i) {
            ans += get(a[i]);
        }

        cout << ans << "\n";
    }
    return 0;
}

