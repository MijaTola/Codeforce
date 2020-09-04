#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long n,g,b;
        cin >> n >> g >> b;
        long long mid = (n + 1) / 2;
        
        long long dv = mid / g + (mid % g != 0);
        long long mn = b * (dv - 1) + mid;
        long long left = max(0ll,n - mn);
        cout << mn + left << "\n";
        
    }
    return 0;
}

