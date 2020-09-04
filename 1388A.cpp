#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int x;
        cin >> x;

        int y = x - 30;

        if(y > 0 and y != 6 and y != 10 and y != 14) {
            cout << "YES\n";
            cout << "6 10 14 " << y << "\n";
            continue;
        }
        
        y = x - 31;
        if(y > 0 and y != 6 and y != 10 and y != 15) {
            cout << "YES\n";
            cout << "6 10 15 " << y << "\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}

