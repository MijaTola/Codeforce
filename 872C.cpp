#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        if(x < 4 or x == 7 or x == 11 or x == 5) {
            cout << -1 << "\n";
        } else if(x & 1) {
            x -= 9;
            cout << x / 4 + 1 << "\n"; 
        } else {
            x -= 4;
            cout << x / 4 + 1 << "\n"; 
        }
    }
    return 0;
}

