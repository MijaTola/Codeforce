#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t; cin >> t;
    while(t--) {
        int x;
        cin >> x;

        for (int i = 1; i <= 1000; ++i) {
            if(x % i == 0 and 180 % (x / i) == 0) {
                cout <<  x / i << "\n";
                break;
            }
        }

    }
    return 0;
}

