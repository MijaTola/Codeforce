#include <bits/stdc++.h>

using namespace std;

int win[100];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;   
        
        if(n == 1) {
            cout << "FastestFinger\n";
            continue;
        }
        bool flag = 0;
        for (int i = 3; i * i <= n; i++) {
            if(n % i == 0) {
                int x = n / i;
                flag |= (x % 2 == 0 and i & 1)  or (x % 2 % 2 != 0 and i % 2 == 0);
            }
        }

        if(flag or n & 1 or n == 2) cout << "Ashishgup\n";
        else cout << "FastestFinger\n";
    }
    return 0;
}

