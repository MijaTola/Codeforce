#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        if(n <= k) cout << "1\n";
        else {
            long long mx = 1;

            for (long long i = 1; i * i <= n and i <= k; ++i) {
                if(n % i == 0) {
                    mx = max(mx, i);
                    long long dv = n / i;
                    if(n / i <= k) mx = max(mx, dv);
                }
            }
            cout << n / mx << "\n";
        }


    }
    return 0;
}

