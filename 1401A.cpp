#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        
        if(k == 0) {
            if(n & 1) cout << "1\n";
            else cout << "0\n";
            continue;
        }

        if(k > n) {
            cout << abs(n - k) << "\n";
        } else {
            if(k & 1) {
                if(n & 1) cout << "0\n";
                else cout << "1\n";
            } else {
                if(n & 1) cout << "1\n";
                else cout << "0\n";
            }
        }
    }
    return 0;
}

