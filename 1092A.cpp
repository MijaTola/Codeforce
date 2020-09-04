#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int f = n / k;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < f and n; ++j) {
                cout << (char)(i + 'a');
                n--;
            }
        }

        while(n--) cout << "a";
        cout << "\n";
    }
    return 0;
}

