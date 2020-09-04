#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int x,y,n;
        cin >> x >> y >> n;
        
        int mod = n % x;

        int df = (mod - y + x) % x;
        cout << n - df << "\n";
    }
    return 0;
}

