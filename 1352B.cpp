#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;

        if((n - (k - 1)) & 1 and (n - (k - 1)) > 0) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; ++i)
                cout << "1 ";
            cout << n - (k - 1) << "\n";
        } else if( (n - 2 * (k - 1)) % 2 == 0 and (n - 2 * (k - 1)) > 0) {
            cout << "YES\n";
            for (int i = 0; i < k - 1; ++i)
                cout << "2 ";
            cout << n - 2 * (k - 1) << "\n";
        } else cout << "NO\n";
    }
    return 0;
}

