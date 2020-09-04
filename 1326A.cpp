#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        if(n == 1) {
            cout << "-1\n";
            continue;
        }
        if((3 * n) % 3 != 0) {
            for (int i = 0; i < n; ++i)
                cout << 3;
            cout << "\n";
            continue;
        } else {
            cout << "2";
            for (int i = 0; i < n - 1; ++i)
                cout << "3";
            cout << "\n";
            continue;
        }
    }
    return 0;
}

