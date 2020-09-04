#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int x,y,l,r;
        cin >> x >> y >> l >> r;
        
        long long a = -1, b = 1e9;
        
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            long long dl = l * mid + x;
            long long dr = y - r * mid;
            if(dr <= dl) b = mid;
            else a = mid;
        }
        
        long long dl = l * b + x;
        long long dr = y - r * b;
        if(dl == dr) cout << b << "\n";
        else cout << -1 << "\n";
        
    }
    return 0;
}

