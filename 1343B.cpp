#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        
        int dv = n / 2;
        if(dv & 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        long long total = 0;
        for (int i = 0; i < n / 2; i++) {
            cout << 2 * i + 2 << " ";
            total += 2 * i + 2;
        }
            

        long long sum = 0;
        for (int i = 0; i < n / 2 - 1; ++i) {
            sum += 2 * i + 1;
            cout << 2 * i + 1 << " ";
        }
        cout << total - sum << "\n";
    }
    return 0;
}

