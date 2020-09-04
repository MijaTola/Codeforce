#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long long sum = 1;
        long long p = 1;
        for (int i = 2; i <= 31; ++i) {
            p <<= 1;
            sum += p;
            if(n % sum == 0) break;
        }
        cout << n / sum << "\n";
    }
    return 0;
}

