#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long x,y,k;
        cin >> x >> y >> k;
            
        cout << (y * k + k - 1) / (x - 1) + (  (y * k + k - 1) % (x - 1) != 0 )+ k << "\n";
    }
    return 0;
}

