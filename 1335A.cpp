#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        cout << max(0, n / 2 - (int)(n % 2 == 0)) << "\n";
    }
    return 0;
}

