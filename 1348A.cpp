#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;

        long long total = (1ll << n);
    
        for (int i = 1; i <= n / 2 - 1; ++i)
            total += (1ll << i);

        for (int i = n / 2; i < n; ++i)
            total -= (1ll << i);
        cout << total << "\n";
    }
    return 0;
}

