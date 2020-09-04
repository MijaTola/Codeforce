#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;

        long long l = -1, r = 1e9;

        if(b >= a) {
            cout << b << "\n";
            continue;
        }

        while(r - l > 1) {
            long long mid = (r + l) / 2;
            if(b + (c - d) * mid >= a) r = mid;
            else l = mid;
        }

        
        if(r == 1e9) cout << "-1\n";
        else cout << b + c * r << '\n';

    }
    return 0;
}

